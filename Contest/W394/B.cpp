/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 22:39:54
*********************************************/

using i64 = long long;

class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.length();

        vector<array<int, 2>> occs(26);
        for (int i = 0; i < 26; i++) {
            occs[i][0] = -1;
            occs[i][1] = n;
        }
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isupper(c)) {
                int o = c - 'A';
                occs[o][1] = min(occs[o][1], i);
            } else {
                int o = c - 'a';
                occs[o][0] = i;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (occs[i][0] == -1 || occs[i][1] == n) {
                continue;
            }
            ans += int(occs[i][0] < occs[i][1]);
        }
        return ans;
    }
};

// ~ JustJie