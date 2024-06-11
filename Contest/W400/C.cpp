/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 13:12:32
*********************************************/

using i64 = long long;
using Info = pair<int, char>;

constexpr int A = 26;

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();

        vector<vector<int>> pos(A);
        set<int> pq;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    auto a = *pq.begin();
                    pos[a].pop_back();
                    if (pos[a].empty()) {
                        pq.erase(pq.begin());
                    }
                }
            } else {
                int o = s[i] - 'a';
                pos[o].push_back(i);
                pq.insert(o);
            }
        }

        vector<Info> loc;
        for (int a = 0; a < A; a++) {
            for (int i : pos[a]) {
                loc.emplace_back(i, a);
            }
        }

        sort(loc.begin(), loc.end());

        string ans;
        for (auto [_, c] : loc) {
            ans += (c + 'a');
        }
        return ans;
    }
};

// ~ JustJie