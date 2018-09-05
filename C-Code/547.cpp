/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
*/

class Solution {
public:
    int Father[10010] = {0};
    void Init()
    {
        for(int i=0 ; i<10010 ; i++)
            Father[i] = i;
    }
    int FindFather(int i)
    {
        int x = i;
        while(x != Father[x])
            x = Father[x];
        int t = i,a;
        while(t != Father[t])
        {
            a = Father[t];
            Father[t] = x;
            t = a;
        }
        return x;
    }
    void Union(int x,int y)
    {
        int a = FindFather(x);
        int b = FindFather(y);
        if(a != b)
            Father[a] = b;
        return;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();
        Init();
        for(int i=0 ; i<len ; i++)
        {
            for(int j=0 ; j<len ; j++)
            {
                if(i!=j && M[i][j]==1)
                {
                    Union(i,j);
                }
            }
        }
        set<int>Res;
        for(int i=0 ; i<len ; i++)
        {
            int t = FindFather(i);
            Res.insert(t);
        }
        return Res.size();
    }
};
