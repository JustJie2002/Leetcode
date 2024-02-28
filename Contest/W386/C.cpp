/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.25.2024 01:27:36
*********************************************/

using i64 = long long;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& a, vector<int>& c) {
        int n = a.size(), m = c.size();

        for (int &id : c) {
            id--;
        }

        auto good = [&](int t) -> bool {
            vector<int> use(n, -1);
            // do reverse so we have a bit more time before
            int res = 0;
            for (int i = 0; i < t; i++) {
                int j = c[i];
                res += int(use[j] == -1);
                use[j] = i;
            }

            if (res != n) {
                return false;
            }

            int free = 0;
            for (int i = 0; i < t; i++) {
                int j = c[i];
                if (use[j] == i) {
                    int need = a[j];
                    if (free < need) {
                        return false;
                    }
                    free -= need;
                } else {
                    free++;
                }
            }

            return true;
        };

        if (!good(m)) {
            return -1;
        }

        int lo = n + accumulate(a.begin(), a.end(), 0), hi = m, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (good(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return hi;
    }
};

// ~ JustJie