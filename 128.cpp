class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int best = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (const auto& x : s) {
            // making sure this number if back-most
            if (!s.count(x - 1)) {
                int y = x + 1;
                while (s.count(y)) y++;
                best = max(best, y - x);
            }
        }
        return best;
    }
};