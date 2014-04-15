#include <stdio.h>
#include <conio.h>

typedef struct pciD
{
    int bus,device;
    int addr[6];
}PCIInfo;

int searchPCIDevice(unsigned int vendorID,unsigned int deviceID,PCIInfo *info)
{
	int i,j;
    int bus,device;
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

void PhsclBaseAddr(PCIInfo *info)
{
	int bus,device;
	int iobase,ioa,temp;
    int i;
	
	bus=info->bus;
    device=info->device;
    iobase=0x80000000+bus*0x10000+(device*8)*0x100;

    ioa=iobase+0x10;
    for(i=0;i<=5;i++)
    {
        _outpd(0xcf8,ioa);
        temp=_inpd(0xcfc);
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

void delay(double seconds)
{
	int al,ah=0;
	unsigned long  cnt,i;
	cnt=(long)(seconds/15.085e-6);
	for(i=0;i<cnt;i++)
	{
		do
		{
			al=_inp(0x61)&0x10;
		}
		while(al==ah);
		ah=al;
	}
}

int phscl_to_lnr(int phscl_addr)
{
	int virtual_addr;
	int *PDE= (int *)0xc0300000;
	int *PTE= (int *)0xc0000000;
	int i,j;
	int result=0;
	
	//使用遍历
	virtual_addr=0x901d5000;
	for(;virtual_addr<0x95fd5000;virtual_addr+=0x00200000){
		PDE = (int *)(((virtual_addr>>21)<<3) & 0x3FF8 + 0xC0600000);
		if(((*PDE)&0x00000001)&&((*PDE)&0xfffff000)){
			PTE = (int *)(((virtual_addr>>12)<<3) & 0x7FFFF8 + 0xC0000000);
			if((*PTE)&0x00000001){
				if(((*PTE)&0xfffff000)==(phscl_addr&0xfffff000))
					result=virtual_addr;
			}		
		}	
	}
	
	return result;
}

//修改师兄unsgined int导致的地址错误，改为int,始终出现蓝屏错误
int phscl_to_lnr_v0(int phscl_addr)
{
	int *pAddr;
	int *PDE= (int *)0xc0300000;
	int *PTE= (int *)0xc0000000;
	int i,j;
	int result=0;
	
	for(i=0;i<1024;i++)
	{
		if((PDE[i]&0xfffff000)&&(PDE[i]&0x00000001))
		{
			for(j=0;j<1024;j++)
			{
				pAddr=(int *)((int)PTE+i*4096+j*4);
				if((*pAddr)&0x00000001)
				{
					if(((*pAddr)&0xfffff000)==(phscl_addr&0xfffff000))
						result=(int) (((i*4*1024*1024+j*4*1024)&0xfffff000)|(phscl_addr&0x00000fff));
						return result;
				}
			}
		}
	}
	return 0;
}