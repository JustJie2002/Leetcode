/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.25.2024 23:02:57
*********************************************/

using i64 = long long;

class Solution {
public:
    string compressedString(string s) {
        s += '0';

        char p = s[0];
        int cnt = 0;
        string ans;
        for (auto c : s) {
            if (c == p) {
                cnt++;
            } else {
                while (cnt) {
                    int take = min(cnt, 9);
                    ans += to_string(take) + p;
                    cnt -= take;
                }
                cnt = 1;
            }
            p = c;
        }
        return ans;
    }
};

// ~ JustJie