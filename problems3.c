//problems003.c
//3. Longest Substring Without Repeating Characters

#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int maxlength;
    int start, end, index;

	if (s[0] == '\0')
    	return 0;

    start = 0;
    end = start + 1;
    maxlength = 0;
    while (*(s+end) != '\0')
    {
    	for (index = start; index < end; index++)
    	{
    		if (s[index] == s[end])
    		{
    			if (end - start > maxlength)
	    		{
					maxlength = end - start;
    			}

    			start = index + 1;
    			break;
    		}
    	}

    	end++;
    }

    if (end - start > maxlength)
	{
		maxlength = end - start;
    }

    return maxlength;
}

int main(int argc, char *argv[])
{
	char a[] = "aubxxbacd";

	printf("Max length of substring for a is %d.\r\n", lengthOfLongestSubstring(a));

	return 0;
}