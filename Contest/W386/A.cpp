/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.24.2024 22:16:31
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& a) {
        map<int, int> freq;
        for (int x : a) {
            freq[x]++;
            if (freq[x] == 3) {
                return false;
            }
        }
        return true;
    }
};

// ~ JustJie