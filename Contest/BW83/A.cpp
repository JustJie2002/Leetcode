/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.07.2024 21:43:19
*********************************************/

using i64 = long long;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        // check for flush
        unordered_set<int> distinct_suits(suits.begin(), suits.end());

        int m = distinct_suits.size();

        if (m == 1) {
            return "Flush";
        }

        unordered_map<int, int> freq;
        int ma = 1;
        for (int rank : ranks) {
            ma = max(ma, ++freq[rank]);
        }

        if (ma >= 3) {
            return "Three of a Kind";
        } else if (ma == 2) {
            return "Pair";
        }
        return "High Card";
    }
};

// ~ JustJie