/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.15.2024 17:44:46
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        const auto ord = [&](char c) { return c - 'a'; };
        const auto chr = [&](int o) { return o + 'a'; };

        array<int, A> occurences {};
        for (char c : s) {
            occurences[ord(c)]++;
        }

        int j = 0;
        string t, res;
        for (char c : s) {
            t += c;
            occurences[ord(c)]--;
            while (j < A && occurences[j] == 0) {
                j++;
            }
            while (!t.empty() && ord(t.back()) <= j) {
                res += t.back();
                t.pop_back();
            }
        }

        return res;
    }
};

// ~ JustJie