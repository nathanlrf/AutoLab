#include <stdio.h>

int main()
{
	int VirtualAddress=0x921d5000;
	int PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	int PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;
	printf("PDE: 0x%x \t PTE : 0x%x\n",PDE,PTE);
	VirtualAddress=0x923d5000;
	PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;
	PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	printf("PDE: 0x%x \t PTE : 0x%x\n",PDE,PTE);
	VirtualAddress=0x925d5000;
	PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;
	PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	printf("PDE: 0x%x \t PTE : 0x%x\n",PDE,PTE);
	VirtualAddress=0x927d5000;
	PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;
	PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	printf("PDE: 0x%x \t PTE : 0x%x\n",PDE,PTE);
	VirtualAddress=0x929d5000;
	PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;
	PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	printf("PDE: 0x%x \t PTE : 0x%x\n",PDE,PTE);
	VirtualAddress=0x931d5000;
	PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;
	PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	printf("PDE: 0x%x \t PTE : 0x%x\n",PDE,PTE);
	return 0;
}