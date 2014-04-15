#include <stdio.h>

int main()
{
	unsigned int VirtualAddress=0x921d5000;
	unsigned int PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	unsigned int PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;

	unsigned int va;
	unsigned int *pde2;
	unsigned int *pte2;

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
	va=VirtualAddress;
	pde2 = (unsigned int *)(((va>>21)<<3) & 0x3FF8 + 0xC0600000);
	pte2 = (unsigned int *)(((va>>12)<<3) & 0x7FFFF8 + 0xC0000000);
	printf("pde2: 0x%x \t PTE2 : 0x%x\n",pde2,pte2);
	VirtualAddress=0x933d5000;
	PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;
	PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	printf("PDE: 0x%x \t PTE : 0x%x\n",PDE,PTE);
	VirtualAddress=0x935d5000;
	PTE = ((VirtualAddress>>12)<<3) & 0x7FFFF8 + 0xC0000000;
	PDE = ((VirtualAddress>>21)<<3) & 0x3FF8 + 0xC0600000;
	printf("PDE: 0x%x \t PTE : 0x%x\n",PDE,PTE);
	return 0;
}