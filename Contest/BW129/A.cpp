/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.27.2024 14:34:58
*********************************************/

using i64 = long long;

constexpr int N = 3;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& aa) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 1; j++) {
                int w = 0, b = 0;
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        if (aa[i + k][j + l] == 'W') {
                            w++;
                        } else {
                            b++;
                        }
                    }
                }
                if (min(w, b) <= 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

// ~ JustJie