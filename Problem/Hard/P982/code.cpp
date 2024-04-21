/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 20:49:04
*********************************************/

using i64 = long long;

constexpr int LIM = 1 << 16;

class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();

        vector<int> freq(LIM);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[a[i] & a[j]]++;
            }
        }

        int ans = 0;
        for (int x : a) {
            for (int i = 0; i < LIM; i++) {
                if ((x & i) == 0) {
                    ans += freq[i];
                }
            }
        }
        return ans;
    }
};

// ~ JustJie