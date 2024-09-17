/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.13.2024 19:37:18
*********************************************/

using i64 = long long;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& a) {
        int n = a.size();

        auto distinct = a;
        sort(distinct.begin(), distinct.end());
        distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());
        int m = distinct.size();

        int ans = 0;
        unordered_map<int, int> freq;
        for (int l = 0, r = 0; r < n; r++) {
            freq[a[r]]++;
            while (freq.size() == m) {
                ans += n - r;
                if (--freq[a[l]] == 0) {
                    freq.erase(a[l]);
                }
                l++;
            }
        }

        return ans;
    }
};

// ~ JustJie