/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.06.2024 18:01:09
*********************************************/

using i64 = long long;

struct Info {
    char c;
    int freq;
    int id;
    Info(char _c, int _freq, int _id) : c(_c), freq(_freq), id(_id) {}
    int nxt() const {
        if (freq >= 100) {
            return freq - 100 + 1;
        } else if (freq >= 10) {
            return freq - 10 + 1;
        } else if (freq > 1) {
            return freq - 1;
        }
        return 1;
    }
    void out() const {
        printf("%d: %c %d\n", id, c, freq);
    }
    int size() const {
        if (freq >= 100) {
            return 4;
        } else if (freq >= 10) {
            return 3;
        } else if (freq > 1) {
            return 2;
        }
        return 1;
    }
};

bool operator<(const Info& a, const Info& b) {
    return a.nxt() > b.nxt();
}

vector<Info> groupby(string s) {
    int n = s.length();
    s += '#';

    char c = s[0];
    int f = 0;
    vector<Info> grps;
    int id = 0;
    for (int i = 0; i < n + 1; i++) {
        if (s[i] == c) {
            f++;
        } else {
            grps.emplace_back(c, f, id++);
            f = 1;
        }
        c = s[i];
    }

    return grps;
}

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        auto grps = groupby(s);

        priority_queue<Info> pq;
        for (const auto& info : grps) {
            pq.push(info);
        }

        while (!pq.empty() && k) {
            auto info = pq.top();
            pq.pop();
            int rem = min(k, info.nxt());
            info.freq -= rem;
            k -= rem;
            if (info.freq) {
                pq.push(info);
            }
        }

        vector<Info> rest;
        while (!pq.empty()) {
            auto info = pq.top();
            pq.pop();
            rest.push_back(info);
        }

        sort(rest.begin(), rest.end(), 
            [&](auto&& a, auto&& b) {
                return a.id < b.id;
            });

        int ans = 0;
        for (const auto& info : rest) {
            ans += info.size();
        }

        return ans;
    }
};

// ~ JustJie