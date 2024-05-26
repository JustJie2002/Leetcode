/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.25.2024 15:48:35
*********************************************/

using i64 = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int n) {
    return rng() % n;
}

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& s, Master& master) {
        int n = s.size();
        int m = s[0].length();

        vector<int> good(n);
        iota(good.begin(), good.end(), 0);

        auto compare = [&](int a, int b) -> int {
            int res = 0;
            for (int i = 0; i < m; i++) {
                res += (s[a][i] == s[b][i]);
            }
            return res;
        };

        do {
            int pivot = good[random(n)];
            int same = master.guess(s[pivot]);
            if (same == m) {
                return;
            }
            vector<int> passed;
            for (int i : good) {
                if (compare(i, pivot) == same) {
                    passed.push_back(i);
                }
            }
            good = std::move(passed);
            n = good.size();
        } while (true);
    }
};

// ~ JustJie