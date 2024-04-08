/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.06.2024 22:36:02
*********************************************/

using i64 = long long;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& a, int k) {
        int n = a.size();

        int center = n / 2;
        vector<int> less, more, same;
        for (int x : a) {
            if (x < k) {
                less.push_back(x);
            } else if (x == k) {
                same.push_back(x);
            } else {
                more.push_back(x);
            }
        }

        sort(less.begin(), less.end());
        sort(more.rbegin(), more.rend());

        int l = less.size(), s = same.size(), m = more.size();

        i64 ans = 0;
        if (l < center + 1) {
            if (l + s >= center + 1) {
                return 0;
            }
            while (l + s < center + 1) {
                int b = more.back();
                ans += abs(b - k);
                more.pop_back();
                s++;
            }
        } else if (l == center + 1) {
            ans += abs(less.back() - k);
        } else {
            while (l > center) {
                ans += abs(less.back() - k);
                less.pop_back();
                l--;
            }
        }
        return ans;
    }
};

// ~ JustJie