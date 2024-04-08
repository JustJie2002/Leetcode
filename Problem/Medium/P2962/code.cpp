/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.28.2024 23:03:21
*********************************************/

using i64 = long long;

class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();
        int mx = *max_element(a.begin(), a.end());

        vector<int> pos;
        int cnt = 0;
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx) {
                pos.push_back(i);
                cnt++;
            }
            if (cnt >= k) {
                ans += pos[cnt - k] + 1;
            }
        }
        return ans;
    }
};

// ~ JustJie