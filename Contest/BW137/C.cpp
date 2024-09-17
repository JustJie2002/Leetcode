/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.17.2024 10:34:30
*********************************************/

using i64 = long long;

constexpr i64 inf = i64(1e15) + 10;

template<typename T>
bool chmin(T& a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T& a, T b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& aa) {
        int n = aa.size();
        int m = aa[0].size();

        int si, sj;
        int mx = -1e9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (chmax(mx, aa[i][j])) {
                    si = i, sj = j;
                }
            }
        }

        vector<set<pair<int, int>>> s(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s[i].emplace(-aa[i][j], j);
            }
        }


        vector<int> marked(m);
        i64 ans = -inf;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    vector<int> v = {i, j, k};
                    vector<int> mark;
                    do {
                        i64 res = 0;
                        for (int x : v) {
                            auto it = s[x].begin();
                            while (marked[it->second]) {
                                it = next(it);
                            }
                            marked[it->second] = 1;
                            res -= it->first;
                            mark.push_back(it->second);
                        }
                        for (int x : mark) {
                            marked[x] = 0;
                        }
                        if (res > ans) {
                            ans = res;
                        }
                    } while (next_permutation(v.begin(), v.end()));
                }
            }
        }

        return ans;
    }
};

// ~ JustJie