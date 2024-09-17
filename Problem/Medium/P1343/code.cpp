/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.13.2024 22:21:46
*********************************************/

using i64 = long long;

class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int lower) {
        int n = a.size();

        i64 sum = 0;
        for (int i = 0; i < k; i++) {
            sum += a[i];
        }

        // sum / k >= lower
        // sum >= lower * k

        const auto f = [&]() -> bool {
            return sum >= 1LL * lower * k;
        };

        int ans = 0;
        if (sum >= 1LL * lower * k) {
            ans++;
        }

        for (int i = k; i < n; i++) {
            sum += a[i];
            sum -= a[i - k];
            
        }
    }
};

// ~ JustJie