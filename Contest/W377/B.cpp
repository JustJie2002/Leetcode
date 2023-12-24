/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.23.2023 21:31:06
*********************************************/

using i64 = long long;

constexpr int P = int(1e9) + 7;

class Solution {
public:
    int maximizeSquareArea(int n, int m, vector<int>& a, vector<int>& b) {
        a.push_back(1);
        a.push_back(n);
        b.push_back(1);
        b.push_back(m);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        auto get = [&](const auto& v) -> unordered_set<int> {
            int n = v.size();
            unordered_set<int> sides;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    sides.insert(v[j] - v[i]);
                }
            }
            return sides;
        };

        auto sa = get(a);
        auto sb = get(b);

        i64 ans = -1;
        for (i64 x : sa) if (sb.count(x)) {
            i64 area = x * x;
            ans = max(ans, area);
        }

        return ans % P;
    }
};

// ~ JustJie