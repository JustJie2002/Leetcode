/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.15.2024 20:32:33
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& aa) {
        int n = aa.size();

        vector<Info> seg;
        for (int i = 0; i < n; i++) {
            for (int x : aa[i]) {
                seg.push_back({x, i});
            }
        }

        sort(seg.begin(), seg.end());

        int m = seg.size();

        unordered_map<int, int> occs;
        Info ans {-1, inf};
        for (int l = 0, r = 0; r < m; r++) {
            occs[seg[r][1]]++;
            if (occs.size() == n) {
                while (true) {
                    int i = seg[l][1];
                    if (occs[i] - 1 == 0) {
                        break;
                    }
                    occs[i]--;
                    l++;
                }
                Info res {seg[l][0], seg[r][0]};
                if (res[1] - res[0] < ans[1] - ans[0]) {
                    ans = res;
                }
                occs[seg[l][1]]--;
                occs.erase(seg[l][1]);
                l++;
            }
        }

        vector<int> answer(2);
        answer[0] = ans[0];
        answer[1] = ans[1];
        return answer;
    }
};

// ~ JustJie