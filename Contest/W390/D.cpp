/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.23.2024 22:30:16
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> stringIndices(vector<string>& words, vector<string>& queries) {
        int n = words.size(), Q = queries.size();

        Trie trie;
        for (int i = 0; i < n; i++) {
            reverse(words[i].begin(), words[i].end());
            trie.add(words[i], i);
        }

        vector<int> ans(Q);
        for (int q = 0; q < Q; q++) {
            auto& word = queries[q];
            reverse(word.begin(), word.end());
            ans[q] = trie.qry(word);
        }

        return ans;
    }
};

// ~ JustJie