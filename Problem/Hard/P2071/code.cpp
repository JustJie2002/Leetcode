/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.01.2024 21:15:42
*********************************************/

using i64 = long long;
using Pair = pair<int, int>;

class Solution {
public:
    int maxTaskAssign(vector<int>& t, vector<int>& w, int rem, int inc) {
        int n = t.size(), m = w.size();

        sort(t.begin(), t.end());
        sort(w.begin(), w.end());

        vector<bool> marked(n);
        int L = 0;
        for (int i = 0; i < m && L < n; i++) {
            int power = int(upper_bound(t.begin(), t.end(), w[i]) - t.begin()) - 1;
            if (power >= L) {
                marked[L] = true;
            } else if (rem) {
                rem--;
                int on_drug_power = int(upper_bound(t.begin(), t.end(), w[i] + inc) - t.begin()) - 1;
                if (on_drug_power >= L) {
                    marked[on_drug_power] = true;
                }
            }
            while (L < n && marked[L]) {
                L++;
            }
        }

        return accumulate(marked.begin(), marked.end(), 0);
    }
};

// ~ JustJie