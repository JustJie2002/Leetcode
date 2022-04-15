class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> S = {}, T = {};
        for (const auto& c : s)
            S[c - 'a']++;
        for (const auto& c : t)
            T[c - 'a']++;
        return S == T;
    }
};