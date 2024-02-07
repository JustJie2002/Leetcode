/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.04.2024 20:46:52
*********************************************/

using i64 = long long;

class Solution {
public:
    int triangularSum(vector<int>& a) {
        int n = a.size();

        for (int i = n; i > 1; i--) {
            vector<int> b;
            for (int j = 0; j < i - 1; j++) {
                b.push_back((a[j] + a[j + 1]) % 10);
            }
            swap(a, b);
        }

        return a[0];
    }
};

// ~ JustJie