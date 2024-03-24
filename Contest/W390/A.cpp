/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.23.2024 22:48:26
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            array<int, 26> freq {};
            int mx = 0;
            for (int j = i; j < n; j++) {
                mx = max(mx, ++freq[s[j] - 'a']);
                if (mx > 2) {
                    break;
                }
                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

// ~ JustJie