/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 21:54:38
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumRobots(vector<int>& a, vector<int>& b, long long budget) {
        int n = a.size();

        multiset<int> cost;
        int L = 0;
        i64 sum = 0;
        int ans = 0;
        for (int R = 0; R < n; R++) {
            cost.insert(a[R]);
            sum += b[R];
            while (!cost.empty()) {
                int ma = *cost.rbegin();
                if (1LL * ma + 1LL * (R - L + 1) * sum > budget) {
                    cost.erase(cost.find(a[L]));
                    sum -= b[L];
                    L++;
                } else {
                    break;
                }
            }
            ans = max(ans, R - L + 1);
        }

        return ans;
    }
};

// ~ JustJie