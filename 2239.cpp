class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        
        int dist = 1e9;

        for (int i : nums) {
            if (abs(dist) == abs(i)) dist = max(dist, i);
            if (abs(i) < abs(dist)) dist = i;
        }

        return dist;
    }
};