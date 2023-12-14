/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.14.2023 02:15:13
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int n = a.size();

        int ans = 0;
        map<int, int> freq;
        for (int i = 0, j = 0; i < n; i++) {
            if (i > 0) {
                freq[a[i - 1]]--;
            }
            while (j < n) {
                int x = a[j];
                if (freq[x] + 1 <= k) {
                    freq[x]++;
                    j++;
                } else {
                    break;
                }
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};

// ~ JustJie