/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.10.2024 20:00:47
*********************************************/

using i64 = long long;

constexpr int N = 1e3 + 5;

int pos[2][N];
int id;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        id++;
        for (int i = 1; auto v : b) {
            pos[0][v] = i;
            pos[1][v] = id;
            i++;
        }

        sort(a.begin(), a.end(),
            [&](int x, int y) {
                bool x_in = pos[1][x] == id;
                bool y_in = pos[1][y] == id;
                if (x_in && y_in) {
                    return pos[0][x] < pos[0][y];
                } else if (x_in) {
                    return true;
                } else if (y_in) {
                    return false;
                } else {
                    return x < y;
                }
            });

        return a;
    }
};

// ~ JustJie