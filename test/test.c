#include <stdio.h>
#include <stdlib.h>

int func1(int i)
{
	if (i<2)
	{
		return i;
	}
	return func1(i - 1) - func2(i - 1);
}

int func2(int i)
{
	if (i<2)
	{
		return i+1;
	}

	return func2(i - 1) - func1(i - 1);
}

int fun3(int i)
{
	return func1(i)/func2(i)+2020;
}

int main()
{
	printf("%d\n", fun3(10) % 4);
	return 0;
}