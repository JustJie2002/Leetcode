constexpr int N = 9;

class Solution {
public:
    bool checkRows(vector<vector<char>>& board) {
        vector<unordered_set<char>> seen(N);
        for (int row = 0; row < N; row++) {
            for (const auto& x : board[row]) {
                if (x == '.') continue;
                if (seen[row].count(x)) return false;
                seen[row].insert(x);
            }
        }
        return true;
    }

    bool checkCols(vector<vector<char>>& board) {
        vector<unordered_set<char>> seen(N);
        for (int col = 0; col < N; col++) {
            for (int row = 0; row < N; row++) {
                char x = board[row][col];
                if (x == '.') continue;
                if (seen[col].count(x)) return false;
                seen[col].insert(x);
            }
        }
        return true;
    }

    bool checkBoxs(vector<vector<char>>& board) {
        vector<unordered_set<char>> seen(N);
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                char x = board[row][col];
                if (x == '.') continue;
                if (seen[(row / 3) * 3 + col / 3].count(x)) return false;
                seen[(row / 3) * 3 + col / 3].insert(x);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkCols(board) && checkBoxs(board);
    }
};