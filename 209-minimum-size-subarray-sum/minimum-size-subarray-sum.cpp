class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, n = nums.size();
        int currSum = 0, ans = INT_MAX;
        while(end<n)
        {
            currSum = currSum + nums[end];
            while(currSum >= target)
            {
                ans = min(ans, (end-start+1));
                currSum = currSum - nums[start];
                start++;
            }
            end++;
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};