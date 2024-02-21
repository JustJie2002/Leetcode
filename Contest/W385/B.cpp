/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 21:45:17
*********************************************/

using i64 = long long;

constexpr int A = 10;

struct Trie {
    struct Info {
        Info* nex[A];
    };

    Info* head = NULL;
    Trie() { head = new Info(); }

    int ord(char c) { return c - '0'; }

    void add(int x) {
        string s = to_string(x);
        int n = s.size();
        Info* temp = head;
        for (int i = 0; i < n; i++) {
            int x = ord(s[i]);
            if (!temp->nex[x]) {
                temp->nex[x] = new Info();
            }
            temp = temp->nex[x];
        }
    }

    int query(int x) {
        string s = to_string(x);
        int n = s.size();
        Info* temp = head;
        for (int i = 0; i < n; i++) {
            int x = ord(s[i]);
            if (!temp->nex[x]) {
                return i;
            }
            temp = temp->nex[x];
        }
        return n;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        Trie t;
        for (int x : a) {
            t.add(x);
        }
        int res = 0;
        for (int x : b) {
            res = max(res, t.query(x));
        }
        return res;
    }
};

// ~ JustJie