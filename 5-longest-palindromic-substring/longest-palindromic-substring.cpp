class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = INT_MIN;
        string ans = "";
        for(int i=0;i<n;i++)
        {
            int l = i, r = i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                int len = r+1-l;
                if(len>maxi)
                {
                    ans = s.substr(l, len);
                    maxi = len;
                }
                l--;
                r++;
            }
            l = i, r = i + 1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                int len = r+1-l;
                if(len>maxi)
                {
                    ans = s.substr(l, len);
                    maxi = len;
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};