//problems003.c
//3. Longest Substring Without Repeating Characters

#include <string.h>
#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int hashtable[256] = {-1};
    int start = 0;
    int index = 0;
    int maxlength = 0;

    for (index = 0; s[index] != '\0'; index++)
    {
    	if (hashtable[s[index]] > start)
    	{
    		start = hashtable[s[index]];
    	}

    	if (maxlength < index - start + 1)
    	{
    		maxlength = index - start + 1;
    	}

    	hashtable[s[index]] = index + 1;
    }

    return maxlength;
}

int main(int argc, char *argv[])
{
	char a[] = "abc";

	printf("Max length of substring for a is %d.\r\n", lengthOfLongestSubstring(a));

	return 0;
}