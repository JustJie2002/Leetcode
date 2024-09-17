/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.07.2024 01:20:20
*********************************************/

using i64 = long long;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string t;
        for (int i = 0; i < n; i++) {
            t += s[(i + k) % n];
        }
        return t;
    }
};

// ~ JustJie