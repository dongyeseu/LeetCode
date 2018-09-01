/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>num(S.length());
        vector<int>alpha(26);
        for(int i=0 ; i<S.length() ; i++)
        {
            alpha[S[i]-'a'] = i;
        }
        for(int i=0 ; i<S.length() ; i++)
        {
            num[i] = alpha[S[i]-'a'];
        }
        vector<int>Res;
        string s = "";
        int Max = num[0];
        for(int i=0 ; i<S.length() ; i++)
        {
            if(i==Max)
            {
                s = s + S[i];
                Res.push_back(s.length());
                s = "";
                if(i+1<S.length())
                    Max = num[i+1];
            }
            else
            {
                s = s + S[i];
                if(num[i] > Max)
                    Max = num[i];            
            }
        }
        return Res;
    }
};
