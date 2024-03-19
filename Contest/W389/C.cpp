/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 22:34:18
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumDeletions(string s, int k) {
        int n = s.length();

        array<int, 26> freq {};
        for (char c : s) {
            freq[c - 'a']++;
        }

        int ans = n;
        for (int lo = 0; lo <= n; lo++) {
            int res = 0;
            int upper = lo + k;
            for (int a = 0; a < 26; a++) {
                if (freq[a] < lo) {
                    res += freq[a];
                } else if (freq[a] > upper) {
                    res += freq[a] - upper;
                }
            }
            ans = min(ans, res);
        }
        return ans;
    }
};

// ~ JustJie