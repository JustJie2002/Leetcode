/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.13.2024 22:58:57
*********************************************/

using i64 = long long;

class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n - 1; i++) {
            if ((s[i] & 1) == (s[i + 1] & 1)) {
                auto t = s;
                swap(t[i], t[i + 1]);
                ans = min(ans, t);
            }
        }
        return ans;
    }
};

// ~ JustJie