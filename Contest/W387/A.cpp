/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 21:25:34
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> resultArray(vector<int>& a) {
        int n = a.size();

        vector<int> num1, num2;
        num1.push_back(a[0]);
        num2.push_back(a[1]);
        for (int i = 2; i < n; i++) {
            if (num1.back() > num2.back()) {
                num1.push_back(a[i]);
            } else {
                num2.push_back(a[i]);
            }
        }

        for (int x : num2) {
            num1.push_back(x);
        }

        return num1;
    }
};

// ~ JustJie