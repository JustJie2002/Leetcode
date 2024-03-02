/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 17:33:16
*********************************************/

using i64 = long long;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniq;

        for (int x : nums) {
            uniq.insert(x);
        }
        
        return uniq.size() < nums.size();
    }
};

// ~ JustJie