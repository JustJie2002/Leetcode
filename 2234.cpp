class Solution {
public:
    long long maximumBeauty(vector<int>& a, long long f, int T, int F, int P) {
        int n = a.size(), cnt = 0;
        
        for (int i = 0; i < n; i++)
            if (a[i] >= T) cnt++;

        sort(a.begin(), a.end());
        
        if (a[0] >= T) return 1LL * n * F;

        vector<long long> pre(n + 1);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = (long long) pre[i] + a[i];
        }

        auto check = [&](int want, int hi) -> bool {
            auto idx = int(upper_bound(a.begin(), a.begin() + hi + 1, want - 1) - a.begin()) - 1;

            return 1LL * want * (idx + 1) - pre[idx + 1] <= f;          
        };

        long long ans = 1LL * cnt * F;

        for (int i = n - 1; ~i; i--) {
            if (a[i] >= T) continue;

            int lo = 0, hi = T - 1, mid;
            while (lo != hi) {
                int mid = (lo + hi + 1) / 2;
                if (check(mid, i)) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }

            ans = max(ans, 1LL * cnt * F + 1LL * lo * P);

            // make current a T
            int away = T - a[i];
            if (away <= f) {
                cnt += 1;
                f -= away;
                ans = max(ans, 1LL * cnt * F);
            } else break;

        }

        return ans;
    }
};