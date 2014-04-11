//the following functions are nathanlrf-defined
#include <stdio.h>
#include <conio.h>

//store information of bus,device and address in PCIInfo
typedef struct pciD
{
    char bus,device;
    unsigned int addr[6];
}PCIInfo;

//methods

//get the bus number and device number
int searchPCIDevice(unsigned int vendorID,unsigned int deviceID,PCIInfo *info)
{
    char i,j;
    char bus,device;
    unsigned int id,ioa,iod;
    bus=0;
    device=0;
    id=vendorID|(deviceID<<16);
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

//delay function for n*15.085e-6s
//8253/54 chip PB4 on 61H port change every 15.085us
void delay(double seconds)
{
    char al,ah=0;
    unsigned long cnt,i;
    cnt=(long)(seconds/15.085e-6);
    for(i=0;i<cnt;i++)
    {
        do{
            al=_inp(0x61)&0x10;//get the value of PB$
        }
        while(al==ah);
        ah=al;
    }
}

//get the base address with bus and device number
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
        if((temp&0x01==0))
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

//convert physical address to linear address
unsigned int PhysicalAddressToLinearAddress(unsigned int pAddress)//pAddress is the physical memory addr
{
    unsigned int *pAddr;
//     
//      unsigned long long *PageDirectoryEntry=(unsigned long long *)0xC03000000;
//      unsigned long long *PageTableEntry=(unsigned long long *)0xC00000000;
//      unsigned int result;
//     int i,j;
    
    
    
       unsigned long long *PageDirectoryEntry;
       unsigned long long *PageTableEntry;
       unsigned  long addr1,addr2;
       unsigned int result;
       int i,j;
       addr1=0xC03000000;
       addr2=0xC00000000;
       PageDirectoryEntry=(unsigned long long *)addr1;
       PageTableEntry=(unsigned long long *)addr2;
     
   //page directory entry
    
    //=================================================================
    //there is a problem with type cast                              ||
    //unsigned int *PageDirectoryEntry=(unsigned int *)0xC03000000;//||
    //page talbe entry                                               ||
    //unsigned int *PageTableEntry=(unsigned int *)0xC0000000;     //||
    //=================================================================
    
    //rewrite as follows
   /* unsigned  long addr1,addr2;
    addr1=0xC03000000;
    addr2=0xC00000000;
    
    PageDirectoryEntry=
    PageTableEntry=(long long *)addr2;
    */
   
    
    
    for(i=0;i<1024;i++)
    {
        if((PageDirectoryEntry[i]&0xFFFFF000)&&(PageDirectoryEntry[i]&0x00000001))//directory last bit is not zero, this directory is used for physical memory
        {
            for(j=0;j<1024;j++)
            {
                pAddr=(int *)((int)PageTableEntry+i*4096+j*4);
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
