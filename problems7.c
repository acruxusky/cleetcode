//problems7.c
//7. Reverse Integer

#include <stdio.h>
#include <limits.h>

int reverse(int x) 
{
    long int result = 0;
    int z = x;

    while (z != 0)
    {
    	result = result * 10 + z % 10;
    	z = z/10;
    }

    if ((result > INT_MAX) || (result < INT_MIN))
    	result = 0;

    return result;
}

int main(int argc, char *argv[])
{
	int a = 1534236469;

	printf("\r\n a %d reverse %d.\r\n", a, reverse(a));

	return 0;
}