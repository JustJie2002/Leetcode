using i64 = long long;
constexpr i64 p = 1E9 + 7;

/**
 * 
 * Approach: Min Heap + Greedy
 * 
 **/

class Solution {
public:
    int maxPerformance(int n, vector<int>& S, vector<int>& E, int k) {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {E[i], S[i]};
        sort(a.rbegin(), a.rend());
        long long sum = 0, best = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [e, s] : a) {
            pq.emplace(s);
            sum += s;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            best = max(best, sum * e);
        }
        return best % p;
    }
};