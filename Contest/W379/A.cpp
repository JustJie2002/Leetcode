/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 21:30:11
*********************************************/

using i64 = long long;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& mat) {
        int dia = 0, area = 0;
        for (int i = 0; i < mat.size(); i++) {
            const auto& dim = mat[i];
            int w = dim[0], h = dim[1];
            int a = w * w + h * h;
            if (a > dia) {
                dia = a;
                area = w * h;
            } else if (a == dia && w * h > area) {
                dia = a;
                area = w * h;
            }
        }

        return area;
    }
};

// ~ JustJie