class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;
        for(auto it:piles)
            high = max(high, it);
        int ans = high;
        while(low<=high)
        {
            int k = low + (high-low)/2;
            long int hours = 0;
            for(auto it:piles)
            {
                hours += ceil((double)it/k);
            }
            if(hours<=h)
            {
                ans = min(k, ans);
                high = k-1;
            }
            else
            {
                low = k+1;
            }
        }
        return ans;
    }
};