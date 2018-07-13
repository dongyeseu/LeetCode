/*
思路：
将字符对应的Morse密码输入至map中，然后通过find函数来判断是否已经存在这个密码
*/


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string Morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--."\
                            ,"--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int sum = 0;
        map<string,int>Mor;
        for(auto i = words.begin() ; i!=words.end() ; i++)
        {
            string a = "";
            string b = *i;
            for(auto j = b.begin() ; j!=b.end() ;j++)
            {
                a+=Morse[*j-'a'];
            }
            if(Mor.find(a)==Mor.end())
            {
                Mor[a]++;
                sum++;
            }
                
        }
        return sum;
        
    }
};
