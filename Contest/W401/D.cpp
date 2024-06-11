/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 22:28:53
*********************************************/

using i64 = long long;

constexpr int N = 1e5 + 10;

class Solution {
public:
    int maxTotalReward(vector<int>& a) {
        // dp[i]: 
        bitset<N> bs;
        bs.set(0);
        sort(a.begin(), a.end());

        bitset<N> side;
        int i = 0;
        for (int x : a) {
            while (i < x) {
                side.set(i);
                i++;
            }
            bs = bs | ((bs & side) << x);
        }


        for (int j = N - 1; j >= 0; j--) {
            if (bs[j])  {
                return j;
            }
        }
        assert(false);
    }
};

// ~ JustJie