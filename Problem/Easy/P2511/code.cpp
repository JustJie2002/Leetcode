/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 23:41:04
*********************************************/

using i64 = long long;

class Solution {
public:
    int captureForts(vector<int>& a) {
        int n = a.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                int tot = 0;
                for (int l = i - 1; l >= 0; l--) {
                    if (a[l] == -1) {
                        ans = max(ans, tot);
                        break;
                    } else if (a[l] == 0) {
                        tot++;
                    } else {
                        break;
                    }
                }
                tot = 0;
                for (int r = i + 1; r < n; r++) {
                    if (a[r] == -1) {
                        ans = max(ans, tot);
                        break;
                    } else if (a[r] == 0) {
                        tot++;
                    } else {
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

// ~ JustJie