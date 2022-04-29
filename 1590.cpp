class Solution {
public:
    int mod_sub(int a, int b, int p) {
        int w = (a - b) % p;
        if (w < 0) w += p;
        return w;
    } 

    int minSubarray(vector<int>& a, int p) {
        int n = a.size();
        vector<int> psum(n + 1);
        for (int i = 0; i < n; i++) 
            psum[i + 1] = (psum[i] + a[i]) % p;
        // the most we can delete is the whole vector
        int best = n;
        unordered_map<int, int> idx;
        idx[0] = 0;
        for (int i = 0; i < n; i++) {
            int d = psum[i + 1];
            idx[d] = i + 1;
            int w = mod_sub(d, psum[n], p);
            if (idx.count(w))
                best = min(best, i - idx[w] + 1);
        }
        return (best == n ? -1 : best);
    }
};