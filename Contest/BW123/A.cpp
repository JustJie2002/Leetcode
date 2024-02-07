/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.03.2024 14:00:35
*********************************************/

using i64 = long long;

class Solution {
public:
    string triangleType(vector<int>& a) {
        sort(a.begin(), a.end());

        if (a[0] + a[1] <= a[2]) {
            return "none";
        }

        int n = set<int>(a.begin(), a.end()).size();

        if (n == 1) {
            return "equilateral";
        } else if (n == 2) {
            return "isosceles";
        }
        return "scalene";
    }
};

// ~ JustJie