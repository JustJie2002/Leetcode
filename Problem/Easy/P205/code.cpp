/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.01.2024 20:17:50
*********************************************/

using i64 = long long;

constexpr int ASCII = 256;

int mark[ASCII], used[ASCII];

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();

        memset(mark, -1, sizeof(mark));
        memset(used, 0, sizeof(used));

        for (int i = 0; i < n; i++) {
            int so = s[i];
            int to = t[i];
            if (mark[so] != -1) {
                if (mark[so] == to) {
                    continue;
                }
                return false;
            }
            if (used[to]) {
                return false;
            }
            mark[so] = to;
            used[to] = 1;
        }

        return true;
    }
};

// ~ JustJie