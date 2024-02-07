/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.20.2024 21:30:40
*********************************************/

using i64 = long long;

constexpr int A = 26;

constexpr int ord(char c) {
    return c - 'a';
}

class Solution {
public:
    int minimumPushes(string word) {
        array<int, A> freq {};
        for (char c : word) {
            freq[ord(c)]++;
        }

        priority_queue<int> pq;
        for (int a = 0; a < A; a++) {
            if (freq[a]) {
                pq.push(freq[a]);
            }
        }
        priority_queue<int, vector<int>, greater<int>> choice;
        for (int i = 0; i < 8; i++) {
            choice.push(1);
        }

        int res = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            auto press = choice.top();
            choice.pop();
            res += cur * press;
            choice.push(press + 1);
        }

        dbp("TESTING:");
        dbg(res);
        return res;
    }
};

// ~ JustJie