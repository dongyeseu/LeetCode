class Solution {
public:
    int hammingDistance(int x, int y) {
        int sum = 0;
        while(x||y)
        {
            if(x!=0 && y!=0)
            {
                if(x%2 != y%2)
                    sum++;
                x/=2;
                y/=2;
            }
            else if (x!=0 && y==0)
            {
                if(x%2!=0)
                    sum++;
                x/=2;
            }
            else if (y!=0 && x==0)
            {
                if(y%2!=0)
                    sum++;
                y/=2;
            }
        }
        return sum;
    }
};
