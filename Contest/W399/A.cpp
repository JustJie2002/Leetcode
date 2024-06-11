/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.25.2024 23:30:56
*********************************************/

using i64 = long long;

class Solution {
public:
    int numberOfPairs(vector<int>& a, vector<int>& b, int k) {
        unordered_map<int, int> good;
        for (int x : a) {
            if (x % k == 0) {
                good[x / k]++;
            }
        }

        unordered_map<int, int> freq;
        for (int x : b) {
            freq[x]++;
        }

        i64 ans = 0;
        for (const auto& [k, v] : good) {
            for (int i = 1; i * i <= k; i++) {
                if (k % i == 0) {
                    ans += 1LL * v * freq[i];
                    if (i * i != k) {
                        ans += 1LL * v * freq[k / i];
                    }
                }
            }
        }
        return ans;
    }
};

// ~ JustJie