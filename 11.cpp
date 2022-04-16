class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, width, n = height.size();

        for (int i = 0, j = n - 1; i < j; ) {
            width = j - i;
            ans = max(ans, width * min(height[i], height[j]));

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};