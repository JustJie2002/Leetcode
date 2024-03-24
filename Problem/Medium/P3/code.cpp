/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.19.2024 03:34:28
*********************************************/

using i64 = long long;

constexpr int A = 255;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        vector<int> prev(A, -1);
        int l = 0, ans = 0;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            if (prev[c] != -1) {
                int up_to = prev[c];
                while (l <= up_to) {
                    prev[s[l]] = -1;
                    l++;
                }
            }
            prev[c] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// ~ JustJie