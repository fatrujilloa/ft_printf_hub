#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	inc(char **str_ptr)
{
	char *str;

	str = *str_ptr;
	str++;
	//(*str_ptr)++;
	//write(1, str, 1);
}

void plusone(int *t)
{
	(*t)++;
}


int main()
{
	char *str;
	int  *t;
	long long n;
	
	str = (char*)malloc(10);
	str[0] = 'A';
	str[1] = 'B'; 
	write(1, str, 1);
	inc(&str);
	write(1, str, 1);
	write(1, str, -1);
											
	write(1, "a", 5);
	n = (signed char)500;
	printf("This is n = %d", n);
	printf("\n Modulo of negative is %d", 13 % 10);
	return (0);
}
