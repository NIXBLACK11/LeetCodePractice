class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> map;
        int ans =0;
        int start = 0, end = 0, n = s.size();
        while(end<n)
        {
            if(map.find(s[end]) != map.end())
            {
                start = max(start, map[s[end]]+1);
            }
            ans = max(ans, end-start+1);
            map[s[end]]=end;
            end++;
        } 
        return ans;
    }
};