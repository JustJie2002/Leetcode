/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.23.2023 21:30:31
*********************************************/

using i64 = long;

class Solution {
public:
    vector<int> numberGame(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i += 2) {
            swap(a[i], a[i + 1]);
        }

        return a;
    }
};

// ~ JustJie