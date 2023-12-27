class Solution {
public:
    int mySqrt(long long x) 
    {
        long long ans = findSqrt(x);
        if(ans != -1)
        {
            return ans;
        }
        else
        {
            return mySqrt(x-1);
        }
    }
        long long findSqrt(long long x)
        {
            long long lb = 0;
            long long ub = x;
            while(ub >= lb)
            {
                long long mid = (lb+ub)/2;
                long long mul = mid * mid;
                if(mul == x)
                {
                    return mid;
                }
                else if(mul > x)
                {
                    ub = mid-1;
                }
                else
                {
                    lb = mid+1;
                }
            }
            return -1;
        }    
};