/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.15.2024 17:04:26
*********************************************/

using i64 = long long;


// Credit: Jiangly
struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;
        int link;
        array<int, ALPHABET> next;
        Node() : link{}, next{} {}
    };
    
    vector<Node> t;
    
    AhoCorasick() {
        init();
    }
    
    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    
    int add(const vector<int> &a) {
        int p = 1;
        for (auto x : a) {
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        return p;
    }
    
    int add(const string &a, char offset = 'a') {
        vector<int> b(a.size());
        for (int i = 0; i < a.size(); i++) {
            b[i] = a[i] - offset;
        }
        return add(b);
    }
    
    void work() {
        queue<int> q;
        q.push(1);
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            for (int i = 0; i < ALPHABET; i++) {
                if (t[x].next[i] == 0) {
                    t[x].next[i] = t[t[x].link].next[i];
                } else {
                    t[t[x].next[i]].link = t[t[x].link].next[i];
                    q.push(t[x].next[i]);
                }
            }
        }
    }
    
    int next(int p, int x) {
        return t[p].next[x];
    }
    
    int next(int p, char c, char offset = 'a') {
        return next(p, c - 'a');
    }
    
    int link(int p) {
        return t[p].link;
    }
    
    int len(int p) {
        return t[p].len;
    }
    
    int size() {
        return t.size();
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();

        AhoCorasick ac;
        for (const auto& word : words) {
            ac.add(word);
        }
        ac.work();

        vector<int> e(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            cur = ac.next(cur, target[i]);
            if (ac.len(cur) > 0) {
                e[i - ac.len(cur) + 1] = max(e[i - ac.len(cur) + 1], ac.len(cur));
            }
        }

        int ans = 0;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            a = max(a, i + e[i]);
            if (b == i) {
                ans++;
                b = a;
            }
        }
        if (b < n) {
            return -1;
        }
        return ans;
    }
};

// ~ JustJie