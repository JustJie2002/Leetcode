/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 15:40:16
*********************************************/

using i64 = long long;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        int a = 0, b = 0;
        array<int, 10> afreq {}, bfreq {};
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                a++;
            } else {
                afreq[secret[i] - '0']++;
                bfreq[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            b += min(afreq[i], bfreq[i]);
        }

        string sans = to_string(a) + "A" + to_string(b) + "B";
        return sans;
    }
};

// ~ JustJie