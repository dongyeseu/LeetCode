class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num_5 = 0, num_10 = 0, num_20 = 0;
        for(auto bill : bills)
        {
            if(bill == 5)
                num_5++;
            else if(bill == 10)
            {
                num_5--;
                num_10++;
            }
            else if(bill == 20)   
            {
                if(num_10>0)
                {
                    num_5--;
                    num_10--;
                    num_20++;
                }
                else
                {
                    num_5 -= 3;
                }
            }
            if(num_5<0 || num_10<0)
                return false;
        }
        return true;
    }
};
