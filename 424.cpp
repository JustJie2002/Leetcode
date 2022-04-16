class Solution {
private:
    int n;
public:
    int check(string &s, char c, int k) {
        vector<int> pre(n + 1);
        
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (s[i] != c);
        }

        int ans = 0;

        for (int i = 0, j = 0; j <= n; i++) {
            while (j <= n && pre[j] - pre[i] <= k) j++;
            ans = max(ans, j - i - 1);
        }

        return ans;
    }

    int characterReplacement(string s, int k) {
        n = s.size();
        int ans = 0;

        unordered_set<char> uni;
        for (const auto& x : s) uni.insert(x);

        for (const auto& c : uni) {
            ans = max(ans, check(s, c, k));
        }

        return ans;
    }
};