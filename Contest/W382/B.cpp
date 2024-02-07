/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.27.2024 21:31:49
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumLength(vector<int>& a) {
        int n = a.size();

        map<int, int> freq;
        int cnt = 0;
        for (int x : a) {
            if (x == 1) {
                cnt++;
            } else {
                freq[x]++;
            }
        }

        map<int, int> res;
        int ans = 1;
        for (auto& [x, f] : freq) {
            int sq = int(sqrt(x));
            if (sq * sq == x && freq.contains(x)) {
                if (freq[sq] > 1) {
                    ans = max(ans, 1 + 2 * res[sq]);
                    if (f > 1) {
                        res[x] = 1 + res[sq];
                    }
                }
            }
            res[x] = max(res[x], 1);
        }

        if (cnt % 2 == 0) {
            cnt--;
        }
        ans = max(ans, cnt);

        return ans;
    }
};

// ~ JustJie