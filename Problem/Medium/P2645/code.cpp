/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.05.2024 02:16:16
*********************************************/

using i64 = long long;

class Solution {
public:
    int addMinimum(string s) {
        int n = s.length();

        int w = 0;
        auto get = [&]() {
            return w + 'a';
        };

        int ans = 0;
        for (int i = 0; i < n; w = (w + 1) % 3) {
            if (s[i] != get()) {
                ans++;
            } else {
                i++;
            }
        }
        ans += (3 - w) % 3;
        return ans;
    }
};

// ~ JustJie