class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        while(r<n)
        {
            int count = 1;
            while(r+1<n && nums[r]==nums[r+1])
            {
                count++;
                r++;
            }
            for(int i=0;i<min(count, 2);i++)
            {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};