/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

int* histogram = (int*) malloc(sizeof(int) * (numsSize + 1));
memset(histogram, 0, sizeof(int) * numsSize);

for (int index = 0; index < numsSize; index++) {
histogram[nums[index]]++;
}

histogram[0] = 1;
for (int index = 1; index <= numsSize; index++) {
if (histogram[index] == 0) {
histogram[histogram[0]] = index;
histogram[0]++;
}
}
*returnSize = histogram[0] - 1;
return &histogram[1];
