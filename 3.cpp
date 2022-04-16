class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size(), ans = 0;
        unordered_map<char, int> idx;

        int i = 0, j = 0;

        while (true) {
            while (j < n && (!idx.count(s[j]) || idx[s[j]] == -1)) {
                idx[s[j++]] = j;
            }

            ans = max(ans, j - i);

            if (j == n) break;

            while (i <= idx[s[j]]) idx[s[i++]] = -1;
        }

        return ans;
    }
};