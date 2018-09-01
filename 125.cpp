/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

class Solution {
public:
    bool isPalindrome(string s) {
        for(auto i = s.begin() ; i!=s.end() ; i++)
        {
            if(!isalnum(*i))
            {
                i = s.erase(i);
                i--;
            }
            else
                *i = tolower(*i);
        }
        int i = 0, k = s.length()-1;
        while(i < k)
        {
            if(s[i]!=s[k])
                return false;
            else
            {
                i++;
                k--;
            }
        }
        return true;
    }
};
