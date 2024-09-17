/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.13.2024 19:26:55
*********************************************/

using i64 = long long;

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();

        vector<int> lst(n, -1);
        int cnt = 0;
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            int x = f[r];
            while (cnt == 2 && lst[x] == -1) {
                int v = f[l];
                if (lst[v] == l) {
                    lst[v] = -1;
                    cnt--;
                }
                l++;
            }
            if (lst[x] == -1) {
                cnt++;
            }
            lst[x] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// ~ JustJie