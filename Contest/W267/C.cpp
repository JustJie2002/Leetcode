/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.10.2024 23:52:38
*********************************************/

using i64 = long long;

class Solution {
public:
    string decodeCiphertext(string s, int row) {
        int n = s.length();

        int col = n / row;
        vector<string> strs(row);
        for (int i = 0, r = 0; i < n; i += col, r++) {
            strs[r] = s.substr(i, col);
        }

        string ans;
        for (int i = 0; i < col; i++) {
            int r = 0, c = i;
            do {
                ans += strs[r][c];
                r++, c++;
            } while (r < row && c < col);
        }

        while (!ans.empty() && isspace(ans.back())) {
            ans.pop_back();
        }

        return ans;
    }
};

// ~ JustJie