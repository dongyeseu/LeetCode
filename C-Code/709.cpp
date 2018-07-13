class Solution {
public:
    string toLowerCase(string str) {
        for(auto i = str.begin(); i!=str.end();i++)
        {
            if(*i>='A'&&*i<='Z')        
                *i = *i+32;                //将大写字母转变为小写字母
        }
        return str;
    }
};
