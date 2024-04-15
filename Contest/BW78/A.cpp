/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.12.2024 10:21:20
*********************************************/

using i64 = long long;

class Solution {
public:
    int divisorSubstrings(int x, int k) {
        auto s = to_string(x);
        int n = s.length();

        int ans = 0;
        for (int i = 0; i < n - k + 1; i++) {
            int v = stoi(s.substr(i, k));
            cout << v << "\n";
            if (v && x % v == 0) {
                ans++;
            }
        }
        return ans;
    }
};

// ~ JustJie