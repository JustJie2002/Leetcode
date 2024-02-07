/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.06.2024 21:42:11
*********************************************/

using i64 = long long;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> dif(n + 1);
        for (const auto& shift : shifts) {
            int s = shift[0], e = shift[1] + 1, d = shift[2];
            if (d == 0) d = -1;
            dif[s] += d;
            dif[e] -= d;
        }

        for ()
    }
};

// ~ JustJie