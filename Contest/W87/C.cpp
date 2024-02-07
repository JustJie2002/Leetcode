/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 21:11:04
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isNStraightHand(vector<int>& a, int sz) {
        map<int, int> freq;
        for (int x : a) {
            freq[x]++;
        }

        for (auto& [x, f] : freq) {
            int of = f;
            if (of == 0) {
                continue;
            }
            for (int i = 0; i < sz; i++) {
                if (freq[i + x] < of) {
                    return false;
                }
                freq[i + x] -= of;
            }
        }

        return true;
    }
};

// ~ JustJie