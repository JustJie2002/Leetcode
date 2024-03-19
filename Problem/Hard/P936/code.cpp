/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.12.2024 21:27:51
*********************************************/

using i64 = long long;
using Segment = array<int, 2>;

class Solution {
public:
    vector<int> movesToStamp(string st, string t) {
        int n = st.size(), m = t.size();

        vector<bool> marked(m);
        vector<int> ans;

        auto work = [&](int pos) -> bool {
            bool good = false;
            for (int i = 0; i < n; i++) {
                if (marked[pos + i]) {
                    continue;
                }
                if (t[pos + i] != st[i]) {
                    return false;
                }
                good = true;
            }

            if (good) {
                ans.push_back(pos);
                for (int i = 0; i < n; i++) {
                    marked[i + pos] = true;
                }
            }

            return good;
        };

        bool working = true;
        do {
            working = false;
            for (int i = 0; i < m - n + 1; i++) {
                working |= work(i);
            }
        } while (working);

        if (any_of(marked.begin(), marked.end(), [&](bool b) { return !b; })) {
            return {};
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// ~ JustJie