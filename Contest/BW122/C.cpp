/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.09.2024 20:34:09
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumArrayLength(vector<int>& a) {
        int n = a.size();
        
        int mi = *min_element(a.begin(), a.end());
        for (int x : a) {
            if (x % mi) {
                return 1;
            }
        }

        int cnt = count(a.begin(), a.end(), mi);
        return (cnt + 1) / 2;
    }
};

// ~ JustJie