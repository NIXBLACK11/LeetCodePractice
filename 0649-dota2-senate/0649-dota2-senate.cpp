class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad;
        queue<int> dir;
        int n = senate.size();
        for(int i=0;i<n;i++)
        {
            char it = senate[i];
            if(it=='R')
                rad.push(i);
            else
                dir.push(i);
        }
        while(!dir.empty() && !rad.empty())
        {
            int d = dir.front();
            int r = rad.front();
            if(d<r)
            {
                rad.pop();
                dir.pop();
                dir.push(n+d);
            }
            else
            {
                dir.pop();
                rad.pop();
                rad.push(n+r);
            }
        }
        if(dir.empty())
            return "Radiant";
        else
            return "Dire";
    }
};