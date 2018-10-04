//problem004.c
//4. Median of Two Sorted Arrays
//

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int imin;
    int imax;
    int half;

    if(nums1Size > nums2Size)
    {
    	int *temp = nums1;
    	nums1 = nums2;
    	nums2 = temp;
    	int size = nums1Size;
    	nums1Size = nums2Size;
    	nums2Size = size;
    }

    imin = 0;
    imax = nums1Size;
    half = (nums1Size + nums2Size + 1)/2;

    while (imin <= imax)
    {
    	int left = (imin + imax)/2;
    	int right = half - left;

    	if ((left < imax) && (nums2[right - 1] > nums1[left])) //left too small
    	{
    		imin = left + 1;
    	}
    	else if ((left > 0) && (nums1[left - 1] > nums2[right])) //left too big
    	{
    		imax = left - 1;
    	}
    	else //it is ok
    	{
    		int maxleft = 0; // get left number
    		if (left == 0)
    			maxleft = nums2[right - 1];
    		else if (right == 0)
    			maxleft = nums1[left - 1];
    		else
    		{
    			maxleft = nums1[left - 1] > nums2[right - 1] ? nums1[left - 1] : nums2[right - 1];
    		}

    		if ((nums1Size + nums2Size) % 2 == 1) //The length of two array is odd
    			return maxleft;

    		int minright = 0; //get right number
    		if (left == nums1Size)
    			minright = nums2[right];
    		else if (right == nums2Size)
    			minright = nums1[left];
    		else
    			minright = nums1[left] < nums2[right] ? nums1[left] : nums2[right];

    		return (maxleft + minright)/2.0; //The length of two array is even
    	}
    }

    return 0;
}

int main(int argc, char *argv[])
{
	int num1[] = {1, 3};
	int num2[] = {2};

	printf("The median is %lf.\r\n", findMedianSortedArrays(num1, 2, num2, 1));

	return 0;
}