/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.11.2024 23:06:08
*********************************************/

using i64 = long long;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.length();

        array<int, 26> occs = {};
        for (int i = 0; i < n; i++) {
            occs[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(i - occs[t[i] - 'a']);
        }
        return ans;
    }
};

// ~ JustJie