/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.10.2024 21:07:18
*********************************************/

using i64 = long long;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

// #define BROKEN_CODE

#ifdef BROKEN_CODE
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #define dbp(...) cout << __VA_ARGS__ << "\n";
#else
    #define dbg(...) 10082002
    #define dbp(...) "Gimme Internship"
#endif

constexpr int INF = int(1e9) + 5;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        auto dp = vector(n, vector(m, vector<int>(m, -INF)));
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    for (int dj = -1; dj < 2; dj++) {
                        int nj = j + dj;
                        if (nj < 0 || nj >= m) {
                            continue;
                        }
                        for (int dk = -1; dk < 2; dk++) {
                            int nk = k + dk;
                            if (nk < 0 || nk >= m) {
                                continue;
                            }
                            if (nj == nk) {
                                dp[i][nj][nk] = max(dp[i][nj][nk], dp[i - 1][j][k] + grid[i][nk]);
                            } else {
                                dp[i][nj][nk] = max(dp[i][nj][nk], dp[i - 1][j][k] + grid[i][nj] + grid[i][nk]);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dp[n - 1][i][j]);
            }
        }

        return ans;
    }
};

// ~ JustJie