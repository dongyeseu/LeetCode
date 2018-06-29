/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

int cmp(const void *a,const void * b)
{
    return *(int *)a - *(int *)b;
}

int missingNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=0 ; i<numsSize ; i++)
    {
        if(nums[i]!=i)
            return i;
    }
    return numsSize;
}
