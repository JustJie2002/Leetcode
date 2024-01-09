/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 17:54:14
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> findPeaks(vector<int>& a) {
        int n = a.size();

        vector<int> ans;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > max(a[i - 1], a[i + 1])) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// ~ JustJie