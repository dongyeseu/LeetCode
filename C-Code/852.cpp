//二分查找法

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int Left = 0 , Right = A.size()-1;
        while(Left<Right)
        {
            int mid = Left + (Right - Left)/2;
            if(A[mid]<A[mid+1])
                Left = mid+1;
            else if (A[mid]>A[mid+1])
                Right = mid;
        }
        return Left;
    }
};
