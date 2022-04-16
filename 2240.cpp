class Solution {
public:
    long long waysToBuyPensPencils(int T, int a, int b) {
        
        int mx = T / a;
        long long ans = 0;

        for (int i = 0; i <= mx; i++) {
            ans += 1LL * (T - i * a) / b + 1;
        }

        return ans;
    }
};