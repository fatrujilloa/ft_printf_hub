#include <stdio.h>

int main()
{
	long double f;
	int i;

	f = 21324.54352311111111111111111111;
	i = 0;
	printf("%-100LfA\n\n", f);
	printf("%lld.", (long long)f);
	f = 10 * (f - (long long)f);
	while (f != 0 || i < 45)
	{
		printf("%d", (int)f);
		f = 10 * (f - (long long)f);
		i++;
		if (i > 45)
		{
			printf("\nvlw");
			break;
		}
	}
	return (0);
}
