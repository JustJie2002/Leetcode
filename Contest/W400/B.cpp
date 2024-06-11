/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 13:06:48
*********************************************/

using i64 = long long;
using Seg = array<int, 2>;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        vector<Seg> merged;
        merged.push_back({0, 0});
        for (const auto& e : events) {
            if (e[0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], e[1]);
            } else {
                merged.push_back({e[0], e[1]});
            }
        }

        merged.push_back({days + 1, days + 1});

        int n = merged.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += merged[i][0] - merged[i - 1][1] - 1;
        }
        return ans;
    }
};

// ~ JustJie