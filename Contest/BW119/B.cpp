/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.14.2023 02:11:42
*********************************************/

using i64 = long long;

class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size();
        
        int ans = 0;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && abs(s[j] - s[j - 1]) <= 1) {
                j++;
            }
            int siz = j - i;
            ans += siz / 2;
            i = j;
        }

        return ans;
    }
};


// ~ JustJie