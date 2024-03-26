/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.25.2024 09:33:47
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int n = a.size();

        vector<int> res;
        for (int x : a) {
            int v = abs(x);
            int id = v - 1;
            if (a[id] < 0) {
                res.push_back(v);
            }
            a[id] = -a[id];
        }

        return res;
    }
};

// ~ JustJie