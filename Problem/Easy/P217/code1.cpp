/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 17:27:22
*********************************************/

using i64 = long long;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            int x_freq = ++freq[x];
            if (x_freq >= 2) {
                return true;
            }
        }
        return false;
    }
};

// ~ JustJie