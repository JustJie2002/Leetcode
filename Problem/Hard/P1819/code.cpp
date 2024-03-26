/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.24.2024 21:45:32
*********************************************/

using i64 = long long;

constexpr int LIM = 2e5 + 1;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& a) {
        int n = a.size();

        vector<bool> good(LIM);
        int mx = a[0];
        for (int x : a) {
            good[x] = true;
            mx = max(mx, x);
        }

        int ans = 0;
        for (int x = 1; x < mx + 1; x++) {
            int g = 0;
            for (int m = x; m < mx + 1; m += x) {
                if (good[m]) {
                    g = gcd(g, m);
                }
                if (g == x) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};

// ~ JustJie