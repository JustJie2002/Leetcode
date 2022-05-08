class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector status(m, vector<char>(n, '.'));
        for (const auto& at : guards) {
            int r = at[0], c = at[1];
            status[r][c] = 'G';
        }
        for (const auto& at : walls) {
            int r = at[0], c = at[1];
            status[r][c] = 'W';
        }
        for (int r = 0; r < m; r++) {
            bool seen = false;
            for (int c = 0; c < n; c++) {
                if (status[r][c] == 'G') {
                    seen = true;
                } else if (status[r][c] == 'W') {
                    seen = false;
                } else {
                    if (seen)
                        status[r][c] = 'T';
                }
            }
        }
        for (int r = 0; r < m; r++) {
            bool seen = false;
            for (int c = n - 1; ~c; c--) {
                if (status[r][c] == 'G') {
                    seen = true;
                } else if (status[r][c] == 'W') {
                    seen = false;
                } else {
                    if (seen)
                        status[r][c] = 'T';
                }
            }
        }
        for (int c = 0; c < n; c++) {
            bool seen = false;
            for (int r = 0; r < m; r++) {
                if (status[r][c] == 'G') {
                    seen = true;
                } else if (status[r][c] == 'W') {
                    seen = false;
                } else {
                    if (seen)
                        status[r][c] = 'T';
                }
            }
        }
        for (int c = 0; c < n; c++) {
            bool seen = false;
            for (int r = m - 1; ~r; r--) {
                if (status[r][c] == 'G') {
                    seen = true;
                } else if (status[r][c] == 'W') {
                    seen = false;
                } else {
                    if (seen)
                        status[r][c] = 'T';
                }
            }
        }
        int ret = 0;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (status[r][c] == '.')
                    ++ret;
        return ret;
    }
};