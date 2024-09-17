/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.19.2024 03:34:28
*********************************************/

using i64 = long long;

constexpr int ASCII = 255;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        vector<int> pre_pos(ASCII, -1);
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            char c = s[r];
            if (pre_pos[c] != -1) {
                int up_to = pre_pos[c];
                while (l <= up_to) {
                    pre_pos[s[l]] = -1;
                    l++;
                }
            }
            pre_pos[c] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// ~ JustJie