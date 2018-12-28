# 121. Best Time to Buy and Sell Stock

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

**Example 1:**

```
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```

**Example 2:**

```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```



#### My Answer

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0 , Min = INT_MAX;
        for(auto i : prices)
        {
            if(i < Min) //不断搜索最小值
                Min = i;
            if(i - Min > res)  //搜索可能出现的最大差值
                res = i - Min;        
        }
        return res;
    }
};
```





### Answers

```java
    public int maxProfit(int[] prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.length; i++) {
            maxCur = Math.max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = Math.max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
```





# 746. Min Cost Climbing Stairs

On a staircase, the `i`-th step has some non-negative cost `cost[i]` assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

**Example 1:**

```
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
```



**Example 2:**

```
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
```



**Note:**

1. `cost` will have a length in the range `[2, 1000]`.
2. Every `cost[i]` will be an integer in the range `[0, 999]`.

### My Answer

```c++
class Solution {
public:
    map<int,int>Num;
    int DP(vector<int>&cost,int i){
        if(i==0)
            return cost[0];
        else if(i == 1)
            return cost[1];
        if(Num.find(i-1) == Num.end())
            Num[i-1] = DP(cost,i-1);
        if(Num.find(i-2) == Num.end())  //避免重复计算
            Num[i-2] = DP(cost,i-2);
        int left = Num[i-1],right = Num[i-2];
        return min(cost[i]+left,cost[i]+right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        return DP(cost,cost.size()-1);
    }
};
```



### Answers

```c++
/*Let dp[i] be the minimum cost to reach the i-th stair.

Base cases:

dp[0]=cost[0]
dp[1]=cost[1]

DP formula:

dp[i]=cost[i]+min(dp[i-1],dp[i-2])*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=(int)cost.size();
        vector<int> dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for (int i=2; i<n; ++i)
            dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
        return min(dp[n-2],dp[n-1]);
    }
};
```





# 70. Climbing Stairs

You are climbing a stair case. It takes *n* steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Note:** Given *n* will be a positive integer.

**Example 1:**

```
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:**

```
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

### My Answer

```c++
class Solution {
public:
    map<int,int>Num;  //必须要有这个记录器，否则内存不够
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(Num.find(n-1) == Num.end())
            Num[n-1] = climbStairs(n-1);
        if(Num.find(n-2) == Num.end())
            Num[n-2] = climbStairs(n-2);
        return Num[n-1]+Num[n-2];
    }
};
```



```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        dp[1] = 1,dp[2]=2;
        for(int i=3 ; i<=n ; i++)
            dp[i] = dp[i-1] + dp[i-2];   //dp方程
        return dp[n];
    }
};
```





# 53. Maximum Subarray

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Example:**

```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Follow up:**

If you have figured out the O(*n*) solution, try coding another solution using the divide and conquer approach, which is more subtle.

### My Answer

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Max = 0 , here = 0;
        int M = INT_MIN;
        for(auto i : nums)
        {
            here = max(0,here+i);
            Max = max(Max,here);
            if(i > M)  //确定是否存在正数
                M = i;
        }
        if(M >=0)
            return Max;
        else
            return M;
        
    }
};
```



### Answers

```java
public int maxSubArray(int[] A) {
        int n = A.length;
        int[] dp = new int[n];//dp[i] means the maximum subarray ending with A[i];
        dp[0] = A[0];
        int max = dp[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            max = Math.max(max, dp[i]);
        }
        
        return max;
}
```





# 198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police**.

**Example 1:**

```
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
```

**Example 2:**

```
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
```

### 

### My Answer

```c++
class Solution {
public:
    map<int,int>Num;
    int DP(vector<int>nums,int n){
        if(n < 0)
            return 0;
        if(Num.find(n-1) == Num.end())
            Num[n-1] = DP(nums,n-1);
        if(Num.find(n-2) == Num.end())
            Num[n-2] = DP(nums,n-2);
        return max(nums[n]+Num[n-2],Num[n-1]);
    }
    int rob(vector<int>& nums) {
        return DP(nums,nums.size()-1);
    }
};
```



```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector<int>dp(n+1,0);
        dp[0] = 0 , dp[1] = nums[0];
        for(int i=1 ; i<n ; i++)
            dp[i+1] = max(nums[i]+dp[i-1],dp[i]);
        return dp[n];
    }
};
```



### Answers

```java
//Step 1. Figure out recursive relation.
//rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )


//Step 2. Recursive (top-down)
public int rob(int[] nums) {
    return rob(nums, nums.length - 1);
}
private int rob(int[] nums, int i) {
    if (i < 0) {
        return 0;
    }
    return Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
}

//Step 3. Recursive + memo (top-down).
int[] memo;
public int rob(int[] nums) {
    memo = new int[nums.length + 1];
    Arrays.fill(memo, -1);
    return rob(nums, nums.length - 1);
}

private int rob(int[] nums, int i) {
    if (i < 0) {
        return 0;
    }
    if (memo[i] >= 0) {
        return memo[i];
    }
    int result = Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    memo[i] = result;
    return result;
}

//Step 4. Iterative + memo (bottom-up)
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int[] memo = new int[nums.length + 1];
    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < nums.length; i++) {
        int val = nums[i];
        memo[i+1] = Math.max(memo[i], memo[i-1] + val);
    }
    return memo[nums.length];
}

//Step 5. Iterative + 2 variables (bottom-up)
/* the order is: prev2, prev1, num  */
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = Math.max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
}

```



```java
#define max(a, b) ((a)>(b)?(a):(b))
int rob(int num[], int n) {
    int a = 0;
    int b = 0;
    
    for (int i=0; i<n; i++)
    {
        if (i%2==0)
        {
            a = max(a+num[i], b);
        }
        else
        {
            b = max(a, b+num[i]);
        }
    }
    
    return max(a, b);
}
```



```java
public int rob(int[] num) {
    int prevNo = 0;
    int prevYes = 0;
    for (int n : num) {
        int temp = prevNo;
        prevNo = Math.max(prevNo, prevYes);
        prevYes = n + temp;
    }
    return Math.max(prevNo, prevYes);
}
```























