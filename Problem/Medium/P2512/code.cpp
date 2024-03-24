/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 23:51:16
*********************************************/

using i64 = long long;

vector<string> cut(string sentence) {
    sentence += " ";

    vector<string> words;
    string word;
    for (char c : sentence) {
        if (isspace(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    
    return words;
}

class Solution {
public:
    vector<int> topStudents(vector<string>& pos, vector<string>& neg, vector<string>& report, vector<int>& s_id, int k) {
        int n = s_id.size();

        unordered_set<string> good, bad;
        for (const auto& sent : pos) {
            auto words = cut(sent);
            for (const auto& word : words) {
                good.insert(word);
            }
        }
        for (const auto& sent : neg) {
            auto words = cut(sent);
            for (const auto& word : words) {
                bad.insert(word);
            }
        }

        vector<int> scores(n);
        for (int i = 0; i < n; i++) {
            const auto& sent = report[i];
            auto words = cut(sent);
            for (const auto& word : words) {
                if (good.contains(word)) {
                    scores[i] += 3;
                } else if (bad.contains(word)) {
                    scores[i] -= 1;
                }
            }
        }

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(),
            [&](int i, int j) {
                if (scores[i] != scores[j]) {
                    return scores[i] > scores[j];
                }
                return s_id[i] < s_id[j];
            });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(s_id[ord[i]]);
        }

        return ans;
    }
};

// ~ JustJie