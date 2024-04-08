/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.06.2024 22:14:50
*********************************************/

using i64 = long long;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int n = a.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[j - 1]) {
                    cnt++;
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
            cnt = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[j - 1]) {
                    cnt++;
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// ~ JustJie