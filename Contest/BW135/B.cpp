/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.20.2024 10:43:37
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumLength(string s) {
        array<int, 26> freq {};
        for (auto c : s) {
            freq[c - 'a']++;
        }

        int ans = 0;
        for (int a = 0; a < 26; a++) {
            if (freq[a] == 0) {
                continue;
            }
            if (freq[a] & 1) {
                ans++;
            } else {
                ans += 2;
            }
        }

        return ans;
    }
};

// ~ JustJie