//problems5-center.c
//5. Longest Palindromic Substring
//Solution: Expand Around Center

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char result[1001] = "";

int expand(char *s, int start, int end)
{
	int left = start;
	int right = end;
	int length = strlen(s);

	while ((left >= 0) && (right < length) && (s[left] == s[right]))
	{
		left--;
		right++;
	}

	return right - left - 1;
}

char* longestPalindrome(char* s) 
{
	int length = strlen(s);
	int index;
	int even, odd, longer;
	int maxlength = 0;
	int maxi = 0;
	int maxj = 0;

	for (index = 0; index < length; index++)
	{
		odd = expand(s, index, index);
		even = expand(s, index, index + 1);

		longer = (odd > even) ? odd : even;

		if (longer > maxlength)
		{
			maxlength = longer;
			maxi = index - (maxlength - 1)/2;
			maxj = index + maxlength/2 - 1;
		}
	}

	strncpy(result, (s + maxi), maxlength);
	result[maxlength] = '\0';
	return result;
}

int main(int argc, char *argv[])
{
	char a[] = "abbd";

	char *p = longestPalindrome(a);

	printf("\r\n Palidsrome of a is %s.\r\n", p);

	return 0;
}