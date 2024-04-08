/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.30.2024 22:41:32
*********************************************/

using i64 = long long;

struct Info {
    int minsum, maxsum, mindiff, maxdiff;
    Info() {}
    Info(const vector<int>& point) {
        minsum = maxsum = point[0] + point[1];
        mindiff = maxdiff = point[0] - point[1];
    }
    int work() {
        return max(maxsum - minsum, maxdiff - mindiff);
    }
};

Info operator+(const Info& a, const Info& b) {
    Info c;
    c.minsum = min(a.minsum, b.minsum);
    c.maxsum = max(a.maxsum, b.maxsum);
    c.mindiff = min(a.mindiff, b.mindiff);
    c.maxdiff = max(a.maxdiff, b.maxdiff);
    return c;
}

class Solution {
public:
    int minimumDistance(vector<vector<int>>& p) {
        int n = p.size();

        vector<Info> pre(n), suf(n);
        pre[0] = Info(p[0]);
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + Info(p[i]);
        }
        suf[n - 1] = Info(p[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + Info(p[i]);
        }

        int ans = min(pre[n - 2].work(), suf[1].work());
        for (int i = 1; i < n - 1; i++) {
            Info info = pre[i - 1] + suf[i + 1];
            ans = min(ans, info.work());
        }
        return ans;
    }
};

// ~ JustJie