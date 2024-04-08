/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.28.2024 17:15:34
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int n = a.size();

        int ans = 0;
        unordered_map<int, int> freq;
        for (int l = 0, r = 0; r < n; r++) {
            int x = a[r];
            freq[x]++;
            while (freq[x] > k) {
                freq[a[l++]]--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// ~ JustJie