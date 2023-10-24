class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        bool containsZero = false;
        int n =grid.size();
        
        // Define the four possible directions (right, left, down, up).
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Initialize the queue and check if there is a '0' in the grid.
        for (int row = 0; row < n; row++) {
            for (int column = 0; column < n; column++) {
                if (grid[row][column] == 1) {
                    q.push({row, column, 0});
                } else {
                    containsZero = true;
                }
            }
        }
        
        // If the queue is empty or there are no '0's in the grid, return -1.
        if (q.empty() || !containsZero) {
            return -1;
        }
        
        int maxDis = -1;
        
        while (!q.empty()) {
            vector<int> cell = q.front();
            q.pop();
            maxDis = max(maxDis, cell[2]);
            
            for (int i = 0; i < direction.size(); i++) {
                int x = direction[i][0] + cell[0];
                int y = direction[i][1] + cell[1];
                
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                    q.push({x, y, cell[2] + 1});
                    grid[x][y] = 1;
                }
            }
        }
        
        return maxDis;
    }
};