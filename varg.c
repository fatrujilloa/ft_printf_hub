#include <stdio.h>
#include <stdarg.h>

int     test(const char* restrict format, ...)
{
	va_list ap;
	int i;

	va_start(ap, format);
	i = 0;
	while (i < 10)
		printf("Line %d:  %d\n", i++, va_arg(ap, int));
	return (0);
}

int main()
{
	test("Test with 2 args %d and %d", 42, 45);
	return (0);
}
