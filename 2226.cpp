class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1, hi = *max_element(candies.begin(), candies.end());
        int best = 0;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            long long res = 0;
            for (int& x : candies) res += (long long) x / mi;
            if (res >= k) {
                best = max(best, mi);
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        return best;
    }
};