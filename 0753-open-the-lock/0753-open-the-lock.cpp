class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        if (deads.count("0000")) return -1; // Check if the initial state is in deadends.

        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");

        int moves = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                string current = q.front();
                q.pop();

                if (current == target) {
                    return moves;
                }

                for (int j = 0; j < 4; j++) {
                    for (int k = -1; k <= 1; k += 2) {
                        char c = current[j];
                        c = (c - '0' + k + 10) % 10 + '0';

                        string next = current;
                        next[j] = c;

                        if (!visited.count(next) && !deads.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }

            moves++;
        }

        return -1; // No solution found.
    }
};
