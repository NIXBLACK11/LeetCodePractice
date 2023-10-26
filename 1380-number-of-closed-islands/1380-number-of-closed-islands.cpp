class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        if (grid[i][j] == 0 && !vis[i][j]) {
            vis[i][j] = 1;
            int result = 1;
            result &= dfs(grid, vis, n, m, i + 1, j);
            result &= dfs(grid, vis, n, m, i, j + 1);
            result &= dfs(grid, vis, n, m, i - 1, j);
            result &= dfs(grid, vis, n, m, i, j - 1);
            return result;
        }
        return 1; // Return 1 if the cell is not water
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    ans += dfs(grid, vis, n, m, i, j);
                }
            }
        }
        return ans;
    }
};
