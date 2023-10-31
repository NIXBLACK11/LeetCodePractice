class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int minVal = *max_element(nums.begin(), nums.end());
        int maxVal = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(), currSum = 0, m = 0;
        int ans = maxVal;
        while(minVal<=maxVal)
        {
            currSum = 0;
            m = 1;
            int mid = minVal + (maxVal - minVal) / 2;
            for(int i=0;i<n;i++)
            {
                currSum += nums[i];
                if(currSum>mid)
                {
                    currSum = nums[i];
                    m++;
                }
            }
            if(m<=k)
            {
                ans = mid;
                maxVal = mid-1;
            }
            else
            {
                minVal = mid+1;
            }
        }
        return ans;
    }
};