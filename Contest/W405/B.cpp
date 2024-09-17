/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.07.2024 01:12:42
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;

        for (int x = 0; x < (1 << n); x++) {
            string mask;
            for (int y = x; y; y >>= 1) {
                mask += char('0' + (y & 1));
            }
            while (mask.size() < n) {
                mask += "0";
            }
            bool bad = false;
            for (int i = 0; i < n - 1 && !bad; i++) {
                bad = bad || (mask[i] == '0' && mask[i + 1] == '0');
            }
            if (!bad) {
                ans.push_back(mask);
            }
        }

        return ans;
    }
};

// ~ JustJie