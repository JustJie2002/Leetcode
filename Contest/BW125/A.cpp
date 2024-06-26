/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 10:28:38
*********************************************/

using i64 = long long;

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int ans = 0;
        for (int x : a) {
            if (x < k) {
                ans++;
            }
        }
        return ans;
    }
};

// ~ JustJie