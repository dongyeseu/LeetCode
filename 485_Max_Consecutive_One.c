/*

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Seen this question in a real interview before?  
*/


int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int n1 = 0,n2 = 0; //n1记录当前连续的1的个数；n2记录连续的1的个数最大值
    int i;//循环计数
    for(i=0 ; i<numsSize ; i++)
    {
        if(nums[i]==1)
        {
            n1++;
            if(n1>n2)
                n2 = n1;
        }
        else
        {
            n1 = 0;
        }
    }
    return n2;
}
