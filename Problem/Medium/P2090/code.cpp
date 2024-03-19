/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.19.2024 02:54:17
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> getAverages(vector<int>& a, int k) {
        int n = a.size();
        int size_of_window = 2 * k + 1;

        vector<int> res(n, -1);
        i64 sum = 0;
        for (int R = 0; R < n; R++) {
            sum += a[R];
            if (R >= 2 * k) {
                int M = R - k;
                res[M] = sum / size_of_window;
                sum -= a[R - 2 * k];
            }
        }

        return res;
    }
};

// ~ JustJie