/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 22:06:20
*********************************************/

using i64 = long long;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

constexpr int N = 6;

// std::random_device rand;
std::mt19937 rng(rand());

class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();

        auto match = [&](auto& a, auto& b) -> int {
            int res = 0;
            for (int i = 0; i < N; i++) {
                res += int(a[i] == b[i]);
            }
            return res;
        };

        vector<int> good;

        for (int i = 0; i < n; i++) {
            good.push_back(i);
        }

        while (true) {
            shuffle(good.begin(), good.end(), rng); // not necessary but might be good
            int idx = good.back();
            good.pop_back();
            int guess = master.guess(words[idx]); // matching
            if (guess == N) return; // found the secret word
            vector<int> nex;
            for (int i : good) {
                if (match(words[i], words[idx]) == guess) { // pruning
                    nex.push_back(i); // valid
                }
            }
            swap(good, nex);
        }

        assert(false);
    }
};

// ~ JustJie