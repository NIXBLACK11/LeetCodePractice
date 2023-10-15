class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1000000007;
        int n = nums.size();
        int result = 0;

        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int left = 0, right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + power[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};