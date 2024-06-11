/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.31.2024 23:12:27
*********************************************/

using i64 = long long;

constexpr int LIM_VOL = 1e9, LIM_DIM = 1e4;

class Solution {
public:
    string categorizeBox(int l, int w, int h, int mass) {
        i64 vol = 1LL * l * w * h;
        
        int mx = max(l, max(w, h));
        bool bu = mx >= LIM_DIM || vol >= LIM_VOL;
        bool he = mass >= 100;
        if (bu && he) {
            return "Both";
        } else if (bu) {
            return "Bulky";
        } else if (he) {
            return "Heavy";
        }
        return "Neither";
    }
};

// ~ JustJie