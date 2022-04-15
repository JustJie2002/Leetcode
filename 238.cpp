class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 1), suf(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] * nums[i];
            suf[n - i - 1] = suf[n - i] * nums[n - i - 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = pre[i] * suf[i + 1];
        }
        return ans;
    }
};