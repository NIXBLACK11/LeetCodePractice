class Solution {
public:
    void gen(int open, int close, string output, vector<string> &ans)
    {
        if(open==0 && close==0)
        {
            ans.push_back(output);
            return;
        }
        if(open>0)
        {
            gen(open-1, close, output+"(", ans);
        }
        if(close>0 && close>open)
        {
            gen(open, close-1, output+")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        int open = n, close = n;
        gen(open, close, output, ans);
        return ans;
    }
};