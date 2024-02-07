/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.03.2024 21:31:32
*********************************************/

using i64 = long long;
using Info = pair<int, int>;

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& aa, int cutoff) {
        int n = aa.size(), m = aa[0].size();

        vector info(n, vector<Info>(m));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                int sum = 0;
                bool good = true;
                for (int di = 0; di < 3 && good; di++) {
                    for (int dj = 0; dj < 3; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        sum += aa[ni][nj];
                        if (di < 2) {
                            int dif = abs(aa[ni][nj] - aa[ni + 1][nj]);
                            if (dif > cutoff) {
                                good = false;
                                break;
                            }
                        }
                        if (dj < 2) {
                            int dif = abs(aa[ni][nj] - aa[ni][nj + 1]);
                            if (dif > cutoff) {
                                good = false;
                                break;
                            }
                        }
                    }
                }
                if (good) {
                    int avg = sum / 9;
                    for (int di = 0; di < 3; di++) {
                        for (int dj = 0; dj < 3; dj++) {
                            int ni = i + di;
                            int nj = j + dj;
                            info[ni][nj].first += avg;
                            info[ni][nj].second++;
                        }
                    }
                }
            }
        }

        vector res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (info[i][j].second == 0) {
                    res[i][j] = aa[i][j];
                } else {
                    res[i][j] = info[i][j].first / info[i][j].second;
                }
            }
        }

        return res;
    }
};

// ~ JustJie