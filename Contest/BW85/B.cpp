/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.06.2024 21:33:13
*********************************************/

using i64 = long long;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        vector<int> o;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                o.push_back(i);
            }
        }

        int m = o.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, o[i] - i);
        }
        return ans;
    }
};

// ~ JustJie