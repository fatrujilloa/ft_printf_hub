#include "printf.h"
#include <stdio.h>

int     ft_printf(const char* restrict format, ...);

int		main()
{
    char *str = "A simple @word@";
	void *ptr;
	
	ptr = (void*)str;
	ft_printf("My Print the void %p.", ptr);
    printf("\nYo Print the void %p.", ptr);
    return (0);
}