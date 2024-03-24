/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.24.2024 03:26:55
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        int l = 0, ans = 0;
        array<int, A> occs {};
        for (int r = 0; r < n; r++) {
            int ord = s[r] - 'a';
            occs[ord]++;

            while (occs[ord] > 2) {
                int o = s[l] - 'a';
                occs[o]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// ~ JustJie