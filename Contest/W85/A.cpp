/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.06.2024 21:46:51
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
        pair<int, int> ax = {a[0], a[2]};
        pair<int, int> bx = {b[0], b[2]};

        if (max(ax.first, bx.first) >= min(ax.second, bx.second)) { 
            return false;
        }

        pair<int, int> ay = {a[1], a[3]};
        pair<int, int> by = {b[1], b[3]};
        if (max(ay.first, by.first) >= min(ay.second, by.second)) {
            return false;
        }

        return true;
    }
};

// ~ JustJie