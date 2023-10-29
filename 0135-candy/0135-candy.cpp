class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>> map(n, vector<int> (2, 0));
        for(int i=0;i<n;i++)
        {
            map[i][0] = ratings[i];
            map[i][1] = i;
        }
        sort(map.begin(), map.end());
        vector<int> candies(n, 1);
        for(auto it:map)
        {
            int i = it[1];
            int temp1 = 1, temp2 = 1;
            if(i-1>=0 && ratings[i-1]<ratings[i])
            {
                temp1 = candies[i-1]+1;
            }
            if(i+1<n && ratings[i+1]<ratings[i])
            {
                temp2 = candies[i+1]+1;
            }
            candies[i] = max(temp1, temp2);
        }
        int ans = 0;
        for(auto it:candies)
        {
            cout<<it<<",";
            ans+=it;
        }
        return ans;
    }
};