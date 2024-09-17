/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.14.2024 22:15:27
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

struct Manacher {
    string word;
    vector<int> man;
    i64 pal_count;

    Manacher() {
        word += '#';
    }

    void add(const string& s) {
        for (char c : s) {
            word += c;
            word += '#';
        }
    }

    char _get(int pos) {
        return word[pos];
    }

    void work() {
        int n = word.length();
        man.resize(n);
        pal_count = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (2 * j - i >= 0 && j + man[j] > i) {
                man[i] = min(man[2 * j - i], j + man[j] - i);
            }
            while (i - man[i] >= 0 && i + man[i] < n && _get(i - man[i]) == _get(i + man[i])) {
                man[i] += 1;
            }
            if (i + man[i] > j + man[j]) {
                j = i;
            }
            pal_count += man[i] / 2;
        }
    }

    int count_pal() {
        return pal_count;
    }

    int get(int mid, bool odd) {
        return man[2 * mid + !odd + 1] - 1;
    }

    bool is_pal(int l, int r) {
        int sz = r - l + 1;
        int mid = (l + r) / 2;
        int len = get(mid, sz & 1);
        return sz <= len;
    }
};

class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();

        auto get = [&](const string& t) {
            Manacher man;
            man.add(t);
            man.work();
            vector<int> pre(n);
            set<int> st;
            priority_queue<Info, vector<Info>, greater<Info>> pq;
            for (int i = 0; i < n; i++) {
                while (!pq.empty() && i > pq.top()[0]) {
                    st.erase(pq.top()[1]);
                    pq.pop();
                }
                int siz = man.get(i, true);
                st.insert(i);
                pq.push({i + siz / 2, i});
                pre[i] = 2 * (i - *st.begin()) + 1;
                if (i) {
                    pre[i] = max(pre[i], pre[i - 1]);
                }
            }
            return pre;
        };


        auto pre = get(s);
        reverse(s.begin(), s.end());
        auto suf = get(s);
        reverse(suf.begin(), suf.end());
        
        i64 ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, 1LL * pre[i] * suf[i + 1]);
        }
        return ans;
    }
};

// ~ JustJie