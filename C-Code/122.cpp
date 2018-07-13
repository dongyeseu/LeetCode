class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len<=1)
            return 0;
        int i=0,sum=0;
        int min = -1,max = -1;
        for(i=0 ; i<len ; i++)
        {
            if(i==0 && prices[i]<=prices[i+1]&&max==-1)
                min = prices[i];
            else if(i!=len-1&&i!=0&&prices[i]<=prices[i+1]&&prices[i]<=prices[i-1]&&max==-1)
                min = prices[i];
            else if(i==len-1&&prices[i]>=prices[i-1]&&min!=-1)
            {
                max = prices[i];
                sum += (max - min);
                max = -1;
                min = -1;
            }
                
            else if(i!=len-1 && i!=0 && prices[i]>=prices[i+1]&&prices[i]>=prices[i-1]&&min!=-1)
            {
                max = prices[i];
                sum += (max - min);
                max = -1;
                min = -1;
            }
        }
        return sum;
    }
};
