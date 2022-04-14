class Solution {
private:
    unordered_set<string> seen;
    queue<string> q;
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        b %= n;
        string ans = string(n, '9');
        q.push(s);
        seen.insert(s);
        while (!q.empty()) {
            auto word = q.front();
            q.pop();

            ans = min(ans, word);

            auto part = word.substr(n - b, b);
            auto rotated = part + word.substr(0, n - b);

            if (!seen.count(rotated)) {
                q.push(rotated);
                seen.insert(rotated);
            }

            // consider which index would be the best to add
            for (int i = 1; i < n; i += 2) {
                word[i] = '0' + ((word[i] - '0' + a) % 10);
            }
            if (!seen.count(word)) {
                q.push(word);
                seen.insert(word);
            }
        }
        return ans;
    }
};