class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>> blue(n);
        vector<vector<int>> red(n);

        vector<int> r(n, 0); // Red Visited
        vector<int> b(n, 0); // Blue Visited

        vector<int> visit(n, 0); // First time visited

        for(auto& i : blueEdges) {
            blue[i[0]].push_back(i[1]);
        }

        for(auto& i : redEdges) {
            red[i[0]].push_back(i[1]);
        }

        queue<pair<int, int>> q;

        vector<int> ans(n, -1);

        q.push({0, -1});

        int count = 0;
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                pair<int, int> temp = q.front();
                q.pop();

                if(visit[temp.first] == 0) {
                    ans[temp.first] = count;
                    visit[temp.first] = 1;
                }

                if(temp.second == -1) {
                    for(auto& j : blue[temp.first]) {
                        q.push({j, 0});
                        b[j] = 1;
                    }

                    for(auto& j : red[temp.first]) {
                        q.push({j, 1});
                        r[j] = 1;
                    }
                }
                else if(temp.second == 1) {
                    for(auto& j : blue[temp.first]) {
                        if(b[j] == 0) {
                            q.push({j, 0});
                            b[j] = 1;
                        }
                    }
                }
                else {
                    for(auto& j : red[temp.first]) {
                        if(r[j] == 0) {
                            q.push({j, 1});
                            r[j] = 1;
                        }
           
           
                    }
                }
            }
            count++;
        }

        return ans;
    }
};