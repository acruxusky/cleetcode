//problems5-bruteforce.c
//5. Longest Palindromic Substring
//Solution: Brute Force

#include <stdio.h>
#include <string.h>

char result[1001] = "";
/*
bool is_palindromic(char *s, int start, int end)
{
	int index;

	for (index = start; index < (start + end + 1)/2; index++)
	{
		if (s[index] != s[end + start - index])
			return false;
	}

	return true;
}
*/

bool is_palindromic(char *s, int start, int end)
{
	int left = start;
	int right = end;
	while (left < right)
	{
		if (*(s + left) != *(s + right))
		{
			return false;
		}
		left++;
		right--;
	}

	return true;
}

char* longestPalindrome(char* s) 
{
	int length;
	int i, j;
	int maxlength = 0;
	int maxi = 0, maxj = 0;

	memset(result, '\0', 1001);

	length = strlen(s);
	for (i = 0; i < length; i++)
	{
		for (j = i; j < length; j++)
		{
			if ((true == is_palindromic(s, i, j)) && (j - i + 1 > maxlength))
			{
				maxlength = j - i + 1;
				maxi = i;
				maxj = j;
			}
		}
	}

	strncpy(result, s + maxi, (maxj - maxi + 1));
	return result;
}

int main(int argc, char *argv[])
{
	char a[] = "cbbcd";

	char *p = longestPalindrome(a);

	printf("\r\n Palidsrome of a is %s", p);

	return 0;
}