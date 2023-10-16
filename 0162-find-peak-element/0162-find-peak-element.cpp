class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            // {
            //     return mid;
            // }
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // The loop ends when left == right, so either left or right can be the peak index.
        return left;
    }
};
