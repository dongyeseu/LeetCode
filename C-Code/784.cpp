/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.
*/

class Solution {
public:
    void backtracking(int i,int N,string &S,vector<string>&Res)
    {
        if(i>=N)
        {
            Res.push_back(S);
            return;
        }
        if(isalpha(S[i]))
        {
            for(int j=0 ; j<=1 ; j++)
            {
                if(j==0)
                    S[i] = tolower(S[i]);
                else
                    S[i] = toupper(S[i]);
                backtracking(i+1,N,S,Res);
            }
        }
        else
            backtracking(i+1,N,S,Res);       
    }
    vector<string> letterCasePermutation(string S) {
        vector<string>Res;
        int N = S.size();
        backtracking(0,N,S,Res);
        return Res;
    }
};
