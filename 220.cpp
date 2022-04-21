using i64 = long long;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<i64> s;
        int n = nums.size();
        for (int i = 0, x; i < n; i++) {
            if (i > k)
                s.erase(s.find(nums[i - k - 1]));
            i64 l = (i64) nums[i] - t;
            i64 r = (i64) nums[i] + t;
            auto idx1 = s.lower_bound(l);
            auto idx2 = s.lower_bound(r);
            if (idx1 != s.end()) {
                x = *(idx1);
                if (abs((i64)x - nums[i]) <= t)
                    return true;
            }
            if (idx2 != s.end()) {
                x = *(idx2);
                if (abs((i64)x - nums[i]) <= t)
                    return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};