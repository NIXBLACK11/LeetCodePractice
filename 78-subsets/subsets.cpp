class Solution {
public:
    vector<vector<int>> output;
    void back(int i, vector<int> nums, vector<int> sub)
    {
        if(i==nums.size())
        {
            output.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        back(i+1, nums, sub);

        // This just removes the char above that was added by append
        sub.pop_back();
        back(i+1, nums, sub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        back(0, nums, sub);
        return output;
    }
};