/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.14.2024 02:13:05
*********************************************/

using i64 = long long;

template <class T>
string format(string sformat, T ) {
    char buf[1000];
    sprintf(buf, sformat, ...);
    return (string) buf;
}

class Solution {
public:
    string findLatestTime(string s) {
        for (int h = 11; h >= 0; h--) {
            for (int m = 59; m >= 0; m--) {
                char buf[6];
                sprintf(buf, "%02d:%02d", h, m);
                bool good = true;
                for (int i = 0; i < 5; i++) {
                    if (s[i] == buf[i] || (s[i] == '?')) {
                    } else {
                        good = false;
                    }
                }
                if (good) {
                    return buf;
                }
            }
        }
        assert(false);
    }
};

// ~ JustJie