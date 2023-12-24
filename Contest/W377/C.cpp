/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.23.2023 21:48:34
*********************************************/

using i64 = long long;

constexpr int A = 26, inf = int(1e9) + 5;
int w[A][A];

constexpr int ord(char c) {
    return c -'a';
}

class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& a, vector<char>& b, vector<int>& c) {
        int n = s.size();
        int m = a.size();

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < A; j++) {
                if (i != j) {
                    w[i][j] = inf;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int from = ord(a[i]), to = ord(b[i]);
            w[from][to] = min(w[from][to], c[i]);
        }

        for (int k = 0; k < A; k++) {
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < A; j++) {
                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
                }
            }
        }

        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            int from = ord(s[i]), to = ord(t[i]);
            if (w[from][to] == inf) {
                return -1;
            }
            ans += w[from][to];
        }

        return ans;
    }
};

// ~ JustJie