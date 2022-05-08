class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string, int> m;
        for (auto& word : words)
            ++m[word];
        string word;
        int ret = 0;
        for (char& x : s) {
            word += x;
            ret += m[word];
        }
        return ret;
    }
};