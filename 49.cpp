class Solution {
public:
    array<int, 26> convert(const string &word) {
        array<int, 26> c = {};
        for (const auto& x : word)
            ++c[x - 'a'];
        return c;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> mp;
        for (const auto& word : strs)
            mp[convert(word)].push_back(word);
        vector<vector<string>> res;
        for (const auto& [_, words] : mp)
            res.push_back(words);
        return res;
    }
};