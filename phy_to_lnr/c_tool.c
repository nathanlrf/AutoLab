#include <stdio.h>
#include <conio.h>

typedef struct pciD
{
    int bus,device;
    unsigned int addr[6];
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
	unsigned int iobase,ioa,temp;
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

unsigned int phscl_to_lnr(unsigned int phscl_addr)
{
	volatile unsigned int *p_addr;
	unsigned int *PDE= (unsigned int *)0xc0300000;
	unsigned int *PTE= (unsigned int *)0xc0000000;
	int i,j;
	unsigned int result;
	
	p_addr=PTE;
	for(;p_addr<0xc04fffff;p_addr++)
	{
		if((*p_addr)&0x1){
			if(((*p_addr)&0xfffff000)==(phscl_addr&0xfffff000))
				return 1;
		}
		
	}
	// for(i=0;i<1024;i++)
	// {
		// if(((*(PDE+i))&0x00000001)&&((*(PDE+i))&0xfffff000))
		// {
			
			// for(j=0;j<1024;j++)
			// {
				// p_addr=(unsigned int *)((unsigned int)PTE+i*4096+j*4);
				// if((*p_addr)&0x00000001)
				// {
					// if(((*p_addr)&0xfffff000)==(phscl_addr&0xfffff000))
					// {
						// result=(unsigned int)(((i*4*1024*1024+j*4*1024)&0xfffff000)|(phscl_addr&0x00000fff));
						// return result;
					// }
				// }
			// }
		// }
	// }
	
	
	
	return 0;
}