/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 13:22:50
*********************************************/

using i64 = long long;

class Solution {
public:
    int missingInteger(vector<int>& a) {
        int n = a.size();

        set<int> s;
        for (int x : a) {
            s.insert(x);
        }

        int sum = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1] + 1) {
                sum += a[i];
            } else {
                break;
            }
        }

        while (s.contains(sum)) {
            sum++;
        }

        return sum;
    }
};

// ~ JustJie