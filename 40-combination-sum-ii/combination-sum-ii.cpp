class Solution {
public:
        vector<vector<int>> ans;
    void dfs(vector<int>& curr, int i, vector<int>& candidates, int target, int sum, int n)
    {
        if(sum==target)
        {
            ans.push_back(curr);
            return;
        }
        if(n<=i || target<sum)
        {
            return;
        }

        curr.push_back(candidates[i]);
        dfs(curr, i+1, candidates, target, sum+candidates[i], n);

        curr.pop_back();
        while(i+1<n && candidates[i]==candidates[i+1])
            i++;
        dfs(curr, i+1, candidates, target, sum, n);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(curr, 0, candidates, target, 0, candidates.size());
        return ans;
    }
};