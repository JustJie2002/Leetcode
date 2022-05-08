class Solution {
private:
    string convert(string s) {
        string word;
        for (char& c : s) {
            if (c == '#') {
                if (!word.empty())
                    word.pop_back();
            } else {
                word += c;
            }
        }
        return word;
    }

public:
    bool backspaceCompare(string s, string t) {
        return convert(s) == convert(t);
    }
};