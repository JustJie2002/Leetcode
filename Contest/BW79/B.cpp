/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.02.2024 22:27:51
*********************************************/

using i64 = long long;

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();

        auto count_words = [&](const auto& message) -> int {
            int cnt = 0;
            int words = 0;
            for (char c : message) {
                if (isspace(c)) {
                    cnt = 0;
                } else if (cnt == 0) {
                    words++;
                    cnt = 1;
                }
            }
            return words;
        };

        map<string, int> freq;
        for (int i = 0; i < n; i++) {
            auto sender = senders[i];
            freq[sender] += count_words(messages[i]);
        }

        int ans = 0;
        string sans;
        for (const auto& [k, v] : freq) {
            if (v > ans) {
                ans = v;
                sans = k;
            } else if (v == ans) {
                sans = k;
            }
        }

        return sans;
    }
};

// ~ JustJie