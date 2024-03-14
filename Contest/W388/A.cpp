/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.09.2024 22:00:06
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& cap) {
        sort(cap.rbegin(), cap.rend());

        int tot = accumulate(a.begin(), a.end(), 0);
        int ans = 0;
        for (int x : cap) {
            ans++;
            tot -= x;
            if (tot <= 0) {
                return ans;
            }
        }

        assert(false);
    }
};

// ~ JustJie