/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.09.2024 22:02:26
*********************************************/

using i64 = long long;

constexpr int A = 26;
struct Trie {
    struct Node {
        Node* nei[A];
        int cnt = 0;
    };
    Node* root;
    Trie() {
        root = new Node();
    }

    int ord(char c) { return c - 'a'; }
    void add(const string& word) {
        int n = word.size();

        for (int i = 0; i < n; i++) {
            Node* node = root;
            for (int j = i; j < n; j++) {
                if (!node->nei[ord(word[j])]) {
                    node->nei[ord(word[j])] = new Node();
                }
                node = node->nei[ord(word[j])];
                node->cnt++;
            }
        }
    }

    string answer(const string& word) {
        int n = word.size();

        for (int i = 0; i < n; i++) {
            Node* node = root;
            for (int j = i; j < n; j++) {
                node = node->nei[ord(word[j])];
                node->cnt--;
            }
        }

        int ans = n + 1;
        string sans;
        for (int i = 0; i < n; i++) {
            Node* node = root;
            for (int j = i; j < n; j++) {
                node = node->nei[ord(word[j])];
                if (node->cnt == 0) {
                    int sz = j - i + 1;
                    if (sz < ans) {
                        ans = sz;
                        sans = word.substr(i, sz);
                    } else if (sz == ans) {
                        sans = min(sans, word.substr(i, sz));
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            Node* node = root;
            for (int j = i; j < n; j++) {
                node = node->nei[ord(word[j])];
                node->cnt++;
            }
        }

        return sans;
    }
};

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& a) {
        int n = a.size();

        Trie t;
        for (const auto& s : a) {
            t.add(s);
        }

        vector<string> ans;
        for (const auto& s : a) {
            ans.push_back(t.answer(s));
        }

        return ans;
    }
};

// ~ JustJie