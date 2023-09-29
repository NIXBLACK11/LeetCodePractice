class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> m;
        set<pair<int, int>> s;
        int n = nums.size();
        for(int i=0;i<n;i++)
            m[nums[i]] = i;
        for(int i=0;i<n;i++)
        {
            int val = nums[i]-k;
            if(m.find(val) != m.end() && m[val] != i)
            {
                s.insert({nums[i], val});
            }
        }
        return s.size();
    }
};