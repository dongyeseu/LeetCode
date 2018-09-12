/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of 
American keyboard like the image below.

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string line_1 = "QWERTYUIOPqwertyuiop";
        string line_2 = "ASDFGHJKLasdfghjkl";
        string line_3 = "ZXCVBNMzxcvbnm";
        map<char,int>letter;
        for(auto c:line_1)
            letter[c] = 1;
        for(auto c:line_2)
            letter[c] = 2;
        for(auto c:line_3)
            letter[c] = 3;
        vector<string>Res;
        for(string t : words)
        {
            int start = letter[t[0]];
            int flag = 1;
            for(char c : t )
            {
                if(letter[c] != start)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                Res.push_back(t);
        }
        return Res;
    }
};




