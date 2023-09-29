class Solution {
public:
    bool legal(vector<vector<char>>& board, int dr, int dc, int rMove, int cMove, char color) {
        int r = rMove + dr;
        int c = cMove + dc;
        int length = 1;

        while (0 <= r && r < board.size() && 0 <= c && c < board[0].size()) {
            length++;
            if (board[r][c] == '.') {
                return false;
            }
            if (board[r][c] == color) {
                return length >= 3;
            }
            r += dr;
            c += dc;
        }
        return false;
    }

    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        board[rMove][cMove] = color;

        for (const auto& dir : directions) {
            int dr = dir.first;
            int dc = dir.second;
            if (legal(board, dr, dc, rMove, cMove, color)) {
                return true;
            }
        }
        return false;
    }
};