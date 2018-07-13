class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>>B;
        int len_a = A.size(),len_b = A[0].size();
        for(int i = 0; i<len_b ; i++)
        {
            vector<int>temp;
            for(int j = 0; j<len_a ; j++)
            {
                temp.push_back(A[j][i]);
            }
            B.push_back(temp);
        }
        return B;
            
    }
};
