#include <stdio.h>
#include <conio.h>

typedef struct pciD
{
    char bus,device;
    unsigned int addr[6];
}PCIInfo;

int searchPCIDevice(unsigned int vendorID,unsigned int deviceID,PCIInfo *info);
void getBaseAddr(char bus,char device,PCIInfo *info);//unused
unsigned int phscl_to_lnr(unsigned int pAddress);

int searchPCIDevice(unsigned int vendorID,unsigned int deviceID,PCIInfo *info)
{
	char i,j;
    char bus,device;
    unsigned int id,ioa,iod;
    bus=0;
    device=0;
    id=vendorID|(deviceID<<16);
    /*
	i=0;
	j=0;
	ioa=0x80000000+bus*0x10000+(device*8)*0x100;
	_outpd(0xcf8,ioa);
	iod=_inpd(0xcfc);
	*/
	for(i=0;i<5;i++)
    {
        for(j=0;j<32;j++)
        {
            bus=i;
            device=j;
            ioa=0x80000000+bus*0x10000+(device*8)*0x100;
            _outpd(0xcf8,ioa);
            iod=_inpd(0xcfc);
            if(iod==id)
            {
                info->bus=bus;
                info->device=device;
                return 1;
            }
        }
    }
	
    return 0;
}

void getBaseAddr(char bus,char device,PCIInfo *info)
{
    unsigned int iobase,ioa,temp;
    int i;
    iobase=0x80000000+bus*0x10000+(device*8)*0x100;
    ioa=iobase+0x10;
    for(i=0;i<=5;i++)
    {
        _outpd(0xcf8,ioa);
        temp=_inp(0xcfc);
        if((temp&0x01)==0)
        {
            temp=temp&0xfffffff0;
        }
        else
        {
            temp=temp&0xfffc;
        }
        info->addr[i]=temp;
        ioa+=0x4;   
    }
}

unsigned int phscl_to_lnr(unsigned int pAddress)
{
    unsigned int *pAddr;
    unsigned int *PageDirectoryEntry;
    unsigned int *PageTableEntry;
    unsigned int PDE,PTE;
    unsigned int result;
    int i,j;
    PDE=0xC0300000;
    PTE=0xC0000000;
    PageDirectoryEntry=(unsigned int *)PDE;
    PageTableEntry=(unsigned int *)PTE;
    
    
    for(i=0;i<1024;i++)
    {
        if((PageDirectoryEntry[i]&0xFFFFF000)&&(PageDirectoryEntry[i]&0x00000001))//directory last bit is not zero, this directory is used for physical memory
        {
            for(j=0;j<1024;j++)
            {
                pAddr=(unsigned int *)((int)PageTableEntry+i*4096+j*4);
                if((*pAddr)&0x00000001)//this page is used for physical memory
                {
                    if(((*pAddr)&0xFFFFF000)==(pAddress&0xFFFFF000))
                    {
                        result=(unsigned int)(((i*4*1024*1024+j*4*1024)&0xFFFFF000)|(pAddress&0x00000FFF));
                        return result;
                    }
                }
                
            }
            
        }
    }
    
    return 0;
}

