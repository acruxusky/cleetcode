		//problems6.c
//6. ZigZag Conversion
//Solution: 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char* convert(char* s, int numRows) 
{
    int length = strlen(s);

    if ((length == 0) || (numRows == 0))
    	return s;

    int unit = 2 * numRows - 2;
    int collum = length/unit;

    if (length % unit != 0)
    {
    	collum++;
    }

    char *t = (char *)malloc(length + 1);
    assert(t);
    t[length] = '\0';

    //for the first row
    int index = 0;
    for (int j = 0; j < collum; j++)
    {
    	*(t + index++) = *(s + j * unit);
    	//index++;
    }

    for (int i = 1; i < numRows; i++)
    {
    	for (int j = 0; j < collum; j++)
    	{
    		int left = j * unit + i;
    		int right = (j + 1) * unit - i;

    		if (left >= length)
    		{
    			break;
    		}

    		*(t + index++) = *(s + left);
    		if ((right < length) && (right != left))
    			*(t + index++) = *(s + right);
    	}
    }

    strncpy(s, t, length);
    free(t);

    return s;
}

int main(int argc, char *argv[])
{
	char a[] = "PAYPALISHIRING";

	char *b = convert(a, 1);

	printf("\r\n a after convert is %s", b);
	printf("\r\n");

	return 0;
}