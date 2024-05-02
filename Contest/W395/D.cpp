/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.27.2024 22:30:09
*********************************************/

using i64 = long long;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& a) {
        int n = a.size();

        i64 m = 1LL * n * (n + 1) / 2LL + 1;
        m /= 2LL;

        auto issoke = [&](int k) {
            unordered_map<int, int> freq;
            i64 res = 0;
            for (int l = 0, r = 0; r < n; r++) {
                freq[a[r]]++;
                while (freq.size() > k) {
                    int x = a[l];
                    if (--freq[x] == 0) {
                        freq.erase(x);
                    }
                    l++;
                }
                res += (r - l + 1);
            }
            return res >= m;
        };

        int lo = 1;
        int hi = set<int>(a.begin(), a.end()).size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (issoke(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
};

// ~ JustJie