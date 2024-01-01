class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string s2 = "";
        for(int i=0;i<n;i++)
        {
            if(isupper(s[i])) {
                s[i] = tolower(s[i]);
            }
            if(isalnum(s[i])) {
                s2.push_back(s[i]);
            }
        }
        n = s2.size();
        int j = n-1;
        for(int i=0;i<n/2;i++)
        {
            if(s2[i]!=s2[j])
            {
                return false;
            }
            j--;
        }
        return true;
    }
};