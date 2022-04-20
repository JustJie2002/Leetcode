class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // non-decreasing
        vector<int> l;
        for (int& x : nums) {
            auto idx = upper_bound(l.begin(), l.end(), x);
            if (idx == l.end()) {
                l.push_back(x);
            } else {
                *(idx) = x;
            }
        }
        int n = nums.size();
        int m = l.size();
        return n - m <= 1;
    }
};