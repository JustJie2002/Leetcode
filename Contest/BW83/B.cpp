/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.07.2024 21:45:58
*********************************************/

using i64 = long long;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        int n = a.size();

        int cnt = 0;
        i64 ans = 0;
        for (int x : a) {
            if (x == 0) {
                cnt++;
            } else {
                cnt = 0;
            }
            ans += cnt;
        }

        return ans;
    }
};

// ~ JustJie