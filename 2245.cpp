class Solution {
public:
    array<int, 2> combine(array<int, 2> &a, array<int, 2> &b) {
        array<int, 2> c;
        for (int i = 0; i < 2; i++) {
            c[i] = a[i] + b[i];
        }
        return c;
    }

    array<int, 2> detach(array<int, 2> &a, array<int, 2> &b) {
        array<int, 2> c;
        for (int i = 0; i < 2; i++) {
            c[i] = a[i] - b[i];
        }
        return c;
    }

    int amin(array<int, 2> a) {
        return min(a[0], a[1]);
    }

    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector store(m, vector<array<int, 2>>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                array<int, 2> c = {};
                while (grid[i][j] % 2 == 0) {
                    c[0] += 1;
                    grid[i][j] /= 2;
                }
                while (grid[i][j] % 5 == 0) {
                    c[1] += 1;
                    grid[i][j] /= 5;
                }
                store[i][j] = c;
            }
        }
        vector row(m, vector<array<int, 2>>(n + 1)), col(n, vector<array<int, 2>>(m + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = combine(row[i][j], store[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                col[i][j + 1] = combine(col[i][j], store[j][i]);
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                array<int, 2> a = detach(row[i][n], row[i][j]);
                array<int, 2> b = detach(col[j][m], col[j][i]);
                array<int, 2> c = combine(row[i][j + 1], col[j][i + 1]);
                array<int, 2> d = combine(row[i][j + 1], b);
                array<int, 2> e = combine(a, col[j][i + 1]);
                array<int, 2> f = combine(a, b);
                ans = max({ans,
                    amin(detach(c, store[i][j])),
                    amin(detach(d, store[i][j])),
                    amin(detach(e, store[i][j])),
                    amin(detach(f, store[i][j]))
                });
            }
        }

        return ans;
    }
};