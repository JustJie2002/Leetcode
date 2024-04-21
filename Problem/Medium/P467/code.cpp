/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 22:36:13
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();

        auto nxt = [&](char c) {
            if (c == 'z') {
                return 'a';
            }
            char new_c = char(c + 1);
            return new_c;
        };

        array<int, A> info {};
        for (int l = 0, r = 0; l < n; l++) {
            int o = s[l] - 'a';
            while (r < n && (l == r or nxt(s[r - 1]) == s[r])) {
                r++;
            }
            info[o] = max(info[o], r - l);
        }

        int ans = 0;
        for (int a = 0; a < A; a++) {
            ans += info[a];
        }

        return ans;
    }
};

// ~ JustJie