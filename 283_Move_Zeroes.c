/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Example:
Input: [0,1,0,3,12]Output: [1,3,12,0,0]
Note:
	1. 
You must do this in-place without making a copy of the array.
	2. 
Minimize the total number of operations.


*/


//思路：遍历数组，找到0，如果0周围非0就交换，否则往后遍历找到非0数，然后交换
void moveZeroes(int* nums, int numsSize) {
    int i; //循环计数
    int j = 1;//与前面的第j个元素互换位置
    int temp; //元素互换位置的中间站
    for(i=0 ; i<numsSize-1 ; i++)
    {
        if(nums[i]==0)
        {
            
            while(nums[i+j]==0)
                j++;
            if(i+j>=numsSize)
                break;
            temp = nums[i];
            nums[i] = nums[i+j];
            nums[i+j] = temp;
        }
    }
    
}
