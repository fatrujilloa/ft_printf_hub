#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *str = "String";
	void *ptr;
	char *str1 = "A";
	unsigned long int n;
	long long k;
	int kk;
	unsigned int l;
	char c;
	long double f;
	
	ptr = (void*)str;
	(void)argc;
	(void)argv;
	//printf("Print the string %s.\n",str);
	//printf("Print the void %p.\n", ptr);
	ptr = (void*)str1;
	//printf("Print the void %p.\n", ptr);
	n = (unsigned long int)str1;
	//printf("The address is %lu\n", n);
	//k = 0;
	k = -12345678123012301;
	kk = -65;
	c = 100;
	l = (unsigned int)kk;
	//printf("\n porcentage test %  +-10.34% \n");
	printf("Full test for integers %+      00025.18d %+d %+hhd %+hd %+lld %+ld ", (int)k, (int)k, (signed char)k, (short)k, (long long)k, (long)k);
	printf("\nFull test for octals %00025.18o %o %hho %ho %llo %lo", (int)k, (int)k, (unsigned char)k,(unsigned short)k, (unsigned long long)k, (unsigned long)k);
	printf("\nFull test for hexa %#00016.18x %#x %#hhx %#hx %#llx %#lx", (int)k, (int)k, (unsigned char)\
		   k,(unsigned short)k, (unsigned long long)k, (unsigned long)k);
    printf("\nFull test for HEXA %00025.18X %X %hhX %hX %llX %lX", (int)k, (int)k, (unsigned char)\
		   k,(unsigned short)k, (unsigned long long)k, (unsigned long)k);
    printf("\nFull test for unsigned %00025.18u %u %hhu %hu %llu %lu", (int)k, (int)k, (unsigned char)\
           k,(unsigned short)k, (unsigned long long)k, (unsigned long)k);
	printf("\nTest char %-30c", 'a');
	printf("\nTest hexa %#10.5x", 245);
	printf("\nTest octal %#04o", 245);
	printf("\nTest string %10sEND", str);
	//printf("\nPrint the void %p.\n", ptr);
	//printf("\n In normal %0+d, in octal %llo\n", l, k);
	//printf("In unsigned decimal %u, mine %ld  \n", -10, -10 + 4294967295);
	//printf("Octal test%#lo\n", 4294967231);
	//printf("%7d\n", 25);
	//printf("%8.7d", 25);
	f = 12443243.412432;
	k = (long long)f;
	printf("\nDouble %0100.111Lf, %Lf, %+f, %.2f, %lld", f, f - k, 0.012, 0.11101, k);
	return (0);
}
