bool IsEelfDividingNumbers(int m)
{
    string a = to_string(m);
    for(char c : a)
    {
        if(c=='0')
            return false;
        else if (m%(c-'0') != 0)
            return false;
    }
    return true;
}

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;
        for(int i=left ; i<=right ; i++)
        {
            if(IsEelfDividingNumbers(i))
                res.push_back(i);
        }
        return res;
    }
};
