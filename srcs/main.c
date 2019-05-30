#include "printf.h"
#include <stdio.h>

int     ft_printf(const char* restrict format, ...);

int		main()
{
	long long k;
	char *str = "A simple @word@";
	void *ptr;
	
	ptr = (void*)str;
	k = -12345678123012301;
	//	ft_printf("This phrase has %      +000025.18d % i %+hhd %+hd %+lld %+ld numbers and one string %s and one octal %llo and one unsigned %u and one hexa %x and one capital hexa %X\n" , k, k, k, k, k, k, "Stringy", k, -65, 15, 16*16*16 + 16 + 14);
	ft_printf("Full test for integers %+      00025.18d %+d %+hhd %+hd %+lld %+ld ", k,k,k,k,k,k);
	ft_printf("\nFull test for octals %00025.18o %#o %hho %ho %llo %lo", k, k, k, k, k, k);
	ft_printf("\nFull test for hexa %00016.18x %#x %hhx %hx %llx %lx", k, k, k, k, k, k);
	ft_printf("\nFull test for HEXA %00025.18X %#X %#hhX %hX %llX %lX", k, k, k, k, k, k);
	ft_printf("\nFull test for unsigned %00025.18u %u %hhu %hu %llu %lu", k, k, k, k, k, k);
	ft_printf("\nString test %-10.2s", "String");
	ft_printf("\nPrint the void %p.", ptr);
	ft_printf("\nFull test for double %0100.35fEND, %#-23fEND", 12.21, 342.213);
	//printf("\nPrint the void %p.", ptr);
	return (0);
}
