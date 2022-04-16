class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int res = 0;
        int maxLeft = 0, maxRight = 0;

        for (int i = 0, j = n - 1; i <= j; ) {
            if (height[i] <= height[j]) {
                if (height[i] >= maxLeft)
                    maxLeft = height[i];
                else
                    res += maxLeft - height[i];
                i++;
            } else {
                if (height[j] >= maxRight)
                    maxRight = height[j];
                else
                    res += maxRight - height[j];
                j--;
            }
        }

        return res;
    }
};