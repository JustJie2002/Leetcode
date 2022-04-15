class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> ind;
        for (int i = 0; i < n; i++) {
            int want = target - nums[i];
            if (ind.count(want)) {
                return {ind[want], i};
            }
            ind[nums[i]] = i;
        }
        return {};
    }
};