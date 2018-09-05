/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    void backtrack(int i,int N,vector<int>&nums,vector<vector<int>>&res)
    {
        if(i>=N)
        {
            res.push_back(nums);
            return;
        }
        for(int j=i ; j<N ; j++)
        {
            swap(nums[j],nums[i]);
            backtrack(i+1,N,nums,res);
            swap(nums[j],nums[i]);
        }
            
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>Res;
        int N = nums.size();
        backtrack(0,N,nums,Res);
        sort(Res.begin(),Res.end());
        return Res;
    }
};
