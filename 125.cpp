class Solution {
public:
    bool isAlphanumeric(char c) {
        if ('a' <= c && c <= 'z') return true;
        if ('A' <= c && c <= 'Z') return true;
        if ('0' <= c && c <= '9') return true;
        return false;
    }

    bool isPalindrome(string s) {
        string word;
        for (const auto& x : s)
            if (isAlphanumeric(x)) word += tolower(x);
        int n = word.size();
        bool ok = true;
        for (int i = 0; i < n / 2; i++)
            ok &= word[i] == word[n - i - 1];
        return ok;
    }
};