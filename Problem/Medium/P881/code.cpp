/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.03.2024 20:04:47
*********************************************/

using i64 = long long;

class Solution {
public:
    int numRescueBoats(vector<int>& w, int lim) {
        int n = w.size();

        sort(w.begin(), w.end());

        int ans = 0;
        for (int l = 0, r = n - 1; l <= r; ans++) {
            if (w[l] + w[r] <= lim) {
                l++;
            }
            r--;
        }
        return ans;
    }
};

// ~ JustJie