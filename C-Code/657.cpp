class Solution {
public:
    bool judgeCircle(string moves) {
        map<char,int>Circle;
        for(auto i = moves.begin() ; i!=moves.end() ; i++)
            Circle[*i]++;
        if(Circle['U']==Circle['D'] && Circle['L']==Circle['R'])
            return true;
        else
            return false;
    }
};
