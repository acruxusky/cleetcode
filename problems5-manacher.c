//problems5-center.c
//5. Longest Palindromic Substring
//Solution: Manacher's algorithm
//Reference: https://www.cnblogs.com/Stay-Hungry-Stay-Foolish/p/7622496.html

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void expand_with_pound(char *s, char *t, int length_of_s)
{
	int index;

	if ((s == NULL) || (t == NULL) || (s[0] == '\0'))
		return;

	for (index = 0; index <= length_of_s; index++)
	{
		*(t + index * 2) = '#';
	}
	
	for (index = 0; index < length_of_s; index++)
	{
		*(t + index * 2 + 1) = *(s + index);
	}

	*(t + 2 * (length_of_s + 1) - 1) = '\0';

	return;
}

char result[1001] = "";

char* longestPalindrome(char* s) 
{
	char *t;
	int *p;
	int index, index_mirror, center, end;
	int length = strlen(s);
	int expand_length = 2 * (length + 1);
	int maxlength, maxindex;

	memset(result, '\0', 1001); 

	if ((s == NULL) || (s[0] == '\0')/* || (length == 1)*/)
		return s;

	t = (char *)malloc(expand_length);
	assert(t);

	p = (int *)malloc(sizeof(int) * expand_length);
	assert(t);

	expand_with_pound(s, t, length);

	center = 0;
	end = 0;
	maxindex = 0;
	maxlength = 1;
	expand_length = expand_length - 1;

	for (index = 1; index < expand_length; index++)
	{
		index_mirror =  2 * center - index;
		if (index < end)
		{
			p[index] = (p[index_mirror] < (end - index)) ? p[index_mirror] : (end - index);
		}
		else
		{
			p[index] = 1;
		}

		while ((index - p[index] >=0) && (index + p[index] < expand_length) && t[index + p[index]] == t[index - p[index]])
		{
			p[index]++;
		}

		if (index + p[index] > end)
		{
			center = index;
			end = center + p[index];
		}

		if (p[index] > maxlength)
		{
			maxindex = index;
			maxlength= p[index];
		}
	}


#ifndef NDEBUG
	for (index = 0; index < expand_length; index++)
	{
		printf("\r\n index %d, length %d, t[index] %c", index, p[index], t[index]);
	}

	printf("\r\n maxindex %d, maxlength %d, t[maxindex] \'%c\'", maxindex, maxlength - 1, t[maxindex]);
	printf("\r\n");
#endif

	strncpy(result, (s + (maxindex - maxlength + 1)/2), maxlength - 1);
	return result;
}

int main(int argc, char *argv[])
{
	char a[] = "cbba";
	
	char *p = longestPalindrome(a);

	printf("\r\n Palindrome of a is %s.\r\n", p);

	return 0;
}