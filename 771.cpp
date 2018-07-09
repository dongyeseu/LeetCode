class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int len = J.size();
        int sum = 0;
        for(int i=0 ; i<len ; i++)
            sum += count(S.begin(),S.end(),J[i]);        //count()函数的使用
        return sum;
            
    }
};
