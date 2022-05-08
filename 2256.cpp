class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> psum(n + 2);
        for (int i = 0; i < n; i++)
            psum[i + 1] = psum[i] + nums[i];
        int most = 0;
        for (int i = 1; i <= n; i++) {
            int left = psum[i] / i;
            int right = (psum[n] - psum[i]) / (n - i);
            most = max(most, abs(left - right));
        }
        return most;
    }
};