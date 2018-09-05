/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    int Father[400100] = {0};
    void Init(int N)
    {
        for(int i=0 ; i<=N+1 ; i++)
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
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int len = grid.size();
        int Len = grid[0].size();
        int z = Len > len ? Len : len;
        Init(z*z);
        for(int i=0 ; i<len ; i++)
        {
            for(int j=0 ; j<Len ; j++)
            {
                if(grid[i][j]=='1')
                {
                    if(i+1<len && grid[i+1][j] == '1')
                    {
                        Union(i*z+j,(i+1)*z+j);
                    }
                    if(i-1>=0 && grid[i-1][j] == '1')
                    {
                        Union(i*z+j,(i-1)*z+j);
                    }
                    if(j+1<Len && grid[i][j+1] == '1')
                    {
                        Union(i*z+j,i*z+j+1);
                    }
                    if(j-1>=0 && grid[i][j-1] == '1')
                    {
                        Union(i*z+j,i*z+j-1);
                    }    
                }
            }
           
        }
        set<int>Res;
        for(int i=0 ; i<len ; i++)
        {
            for(int j=0 ; j<Len ; j++)
            {
                if(grid[i][j] == '1')
                {
                    int t = FindFather(i*z+j);
                    Res.insert(t);
                }
            }
        }
        return Res.size();
    }
};
