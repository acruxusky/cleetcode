//problems5-center.c
//5. Longest Palindromic Substring
//Solution: Dynamic Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TRUE (1)
#define FALSE (0)
typedef char BOOL;
char result[1001] = "";

char* longestPalindrome(char* s) 
{
	int i, j;
	int maxi = 0, maxj = 0;
	int maxlength = 1;
	BOOL *p = NULL;
	int length = strlen(s);
	if (length == 0)
		return s;

	memset(result, '\0', 1001);

	p = (BOOL *)malloc(length * length);
	assert(p);
	memset(p, '\0', (length * length));

	for (i = 0; i < length; i++)
	{
		*(p + i * length + i) = TRUE;
		if ((i + 1 < length) && (s[i] == s[i + 1]))
		{
			*(p + i * length + i + 1) = TRUE;
			maxlength = 2;
			maxi = i;
			maxj = i + 1;
		}
	}

	for (i = length - 1; i >= 0; i--)
	{
		for (j = i + 2; j < length; j++)
		{
			*(p + i * length + j) = (*(p + (i + 1) * length + j - 1)) && (s[i] == s[j]);

			if ((*(p + i * length + j) == TRUE) && (j - i + 1 > maxlength))
			{
				maxlength = j - i + 1;
				maxi = i;
				maxj = j;
			}
		}
	}
	
	strncpy(result, (s + maxi), maxlength);
	return result;
}

int main(int argc, char *argv[])
{
	char a[] = "abbda";

	char *p = longestPalindrome(a);

	printf("\r\n Palidsrome of a is %s.\r\n", p);

	return 0;
}