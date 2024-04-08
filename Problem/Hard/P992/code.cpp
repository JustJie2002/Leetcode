/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.29.2024 20:01:38
*********************************************/

using i64 = long long;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n = a.size();

        auto get = [&](int cutoff) -> int {
            int ans = 0;
            unordered_map<int, int> freq;
            for (int l = 0, r = 0; r < n; r++) {
                freq[a[r]]++;
                while (freq.size() > cutoff) {
                    freq[a[l]]--;
                    if (freq[a[l]] == 0) {
                        freq.erase(a[l]);
                    }
                    l++;
                }
                ans += r - l + 1;
            }
            return ans;
        };

        return get(k) - get(k - 1);
    }
};

// ~ JustJie