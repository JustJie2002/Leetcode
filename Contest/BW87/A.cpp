/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.21.2024 10:19:02
*********************************************/

using i64 = long long;
using Time = pair<int, int>;

const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int conv(const string& date) {
    int m = stoi(date.substr(0, 2));
    int d = stoi(date.substr(3));
    for (int i = 0; i + 1 < m; i++) {
        d += days[i];
    }
    return d;
}

Time to_time(const string& start, const string& end) {
    return {conv(start), conv(end)};
}

class Solution {
public:
    int countDaysTogether(string astart, string aend, string bstart, string bend) {
        Time a_time = to_time(astart, aend);
        Time b_time = to_time(bstart, bend);
        if (a_time > b_time) swap(a_time, b_time);

        if (b_time.first > a_time.second) {
            return 0;
        }

        return min(b_time.second, a_time.second) - b_time.first + 1;
    }
};

// ~ JustJie