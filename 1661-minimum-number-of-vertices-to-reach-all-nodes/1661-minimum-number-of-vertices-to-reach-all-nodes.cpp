class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> incoming(n, -1);
        for(auto it:edges)
        {
            incoming[it[1]] = 1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(incoming[i] == -1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};