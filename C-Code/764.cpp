/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
*/


class Solution {
public:
    int Min(int a,int b)
    {
        return a<b?a:b;
    }
    int Cost(vector<int>&cost,int N,int res[],int len)
    {
        if(N<0)
            return 0;
        if(res[N]>=0)
            return res[N];
        if(N == len)
            res[N] = Min(Cost(cost,N-1,res,len) , Cost(cost,N-2,res,len));
        else
            res[N] = Min(cost[N]+Cost(cost,N-1,res,len),cost[N]+Cost(cost,N-2,res,len));
        return res[N];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if(len==0)
            return 0;
        int res[len+1];
        memset(res,-1,sizeof(int)*(len+1));
        return Cost(cost,len,res,len);
    }
};
