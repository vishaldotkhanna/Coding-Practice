#include<stdio.h>
#include<string.h>

void compute(int *x, int *y, int *z)
{
	*y = *y + 1;
	*z = *z + *x;
	*x = *x + *y + *z;
	printf("In function %d %d %d", *x, *y, *z);
}

int i = 0;

void main()
{
	char a[] = "abcdef";

	printf("%c %c", *(a + 3), 3[a]);

	3[a] = 'X';

	printf("%s", a);
}
