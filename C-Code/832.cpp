class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int Size_1 = A.size();
        for(int i=0 ; i<Size_1 ; i++)
        {
            int Size_2 = A[i].size();
            for(int j=0 ; j<Size_2 ; j++)
            {
              //这一部分可以改为  A[i][j]=!A[i][j];
                A[i][j]==0?A[i][j]=1 : A[i][j]=0;
            }
            //这一部分可以改为 reverse(A[i].begin(),A[i].end());
            for(int j=0 ; j<Size_2/2 ; j++)
            {
                int t;
                t = A[i][Size_2-1-j];
                A[i][Size_2-1-j] = A[i][j];
                A[i][j] = t;
            }
        }
        return A;
    }
};
