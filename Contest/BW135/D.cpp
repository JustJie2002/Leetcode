/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.20.2024 10:20:44
*********************************************/

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

#define BROKEN_CODE

#ifdef BROKEN_CODE
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #define dbp(...) cout << __VA_ARGS__ << "\n";
#else
    #define dbg(...) 10082002
    #define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& g) {
        int n = g.size();

        vector pre(n, vector<i64>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    pre[i][j] = g[i][j];
                } else {
                    pre[i][j] = pre[i - 1][j] + g[i][j];
                }
            }
        }

        // at most 2 peaks
        vector dp(n + 1, vector<i64>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= n; i++) {
                i64 res = (i == n ? 0 : g[i][j]);
                if (j > 0) {
                    res += pre[i - 1][j - 1];
                }
                i64 best = 0;
                if (j > 0) {
                    for (int k = 0; k < n; k++) {
                        if (k <= i - 1) {
                            i64 cur = dp[k][j - 1];
                            if (j - 1 != 0) {
                                cur -= pre[k][j - 1];
                            }
                            best = max(best, cur);
                        } else {
                            i64 cur = dp[k][j - 1];
                            if (j - 1 != 0) {
                                cur -= pre[i - 1][j - 1];
                            }
                            best = max(best, cur);
                        }
                    }
                }

                assert(best >= 0);
                dbg(i, j, best, res);
                if (j < n - 1) {
                    res += pre[i - 1][j + 1];
                    dbg(pre[i - 1][j + 1]);
                    dp[i - 1][j + 1] = max(dp[i - 1][j + 1], res + best);
                } else {
                    dp[i][j] = max(dp[i][j], res + best);
                }

                // if (j < n - 3) {
                //     res = (i == n ? 0 : g[i][j]);
                //     if (j > 0) {
                //         res += pre[i - 1][j - 1];
                //     }
                //     i64 best = 0;
                //     if (j > 1) {
                //         for (int k = 0; k < n; k++) {
                //             if (k <= i - 1) {
                //                 i64 cur = dp[k][j - 1];
                //                 if (j - 1 != 0) {
                //                     cur -= pre[k][j - 1];
                //                 }
                //                 best = max(best, cur);
                //             } else {
                //                 i64 cur = dp[k][j - 1];
                //                 if (j - 1 != 0) {
                //                     cur -= pre[i - 1][j - 1];
                //                 }
                //                 best = max(best, cur);
                //             }
                //         }
                //     }
                //     assert(best >= 0);

                //     for (int k = 1; k <= n; k++) {
                //         if (i == k) {
                //             i64 cur = res + pre[k - 1][j + 2] + best;
                //             if (k != n) {
                //                 cur += g[k][j + 1];
                //             }
                //             dp[k - 1][j + 2] = max(dp[k - 1][j + 2], cur);
                //         } else if (i < k) {
                //             i64 cur = res + pre[k - 1][j + 2] + best;
                //             if (k != n) {
                //                 cur += g[k][j + 1];
                //             }
                //             cur += pre[k - 1][j] - pre[i - 1][j];
                //             cur -= g[i][j];
                //             dp[k - 1][j + 2] = max(dp[k - 1][j + 2], cur);
                //         } else {
                //             i64 cur = res + pre[k - 1][j + 2] + best;
                //             cur += pre[i - 1][j + 1] - pre[k - 1][j + 1];
                //             dp[k - 1][j + 2] = max(dp[k - 1][j + 2], cur);
                //         }
                //     }
                // }
            }
        }

        dbg(dp);

        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

/*
{0, 0, 6, 9, 9}
{0, 0, 9, 6, 9}
{0, 6, 8, 6, 12}
{0, 1, 8, 9, 9}
{0, 1, 8, 9, 14}
{0, 0, 0, 0, 12}

{0, 0, 0, 9, 8}
{0, 0, 4, 6, 9}
{0, 6, 3, 6, 11}
{0, 1, 8, 9, 9}
{0, 1, 8, 9, 14}
{0, 0, 0, 0, 12}
*/

// ~ JustJie