/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.29.2024 19:24:40
*********************************************/

using i64 = long long;
using Date = array<int, 3>;

constexpr int DPM[] { // Days Per Month
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
constexpr int YEARS = 365;

void print(const Date& d) {
    printf("%d/%d/%d\n", d[1], d[2], d[0]);
}

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        auto parse = [&](const string& date) -> Date {
            Date d;
            sscanf(date.c_str(), "%d-%d-%d", &d[0], &d[1], &d[2]);
            return d;
        };
        auto is_leap = [&](int year) -> bool {
            return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
        };
        auto finish_the_year = [&](const Date& date) -> int {
            int res = 0;
            int d = date[2];
            for (int m = date[1]; m <= 12; m++) {
                res += DPM[m] - d + 1;
                if (m == 2) {
                    res += int(is_leap(date[0]));
                }
                d = 1;
            }
            return res;
        };

        Date start = parse(date1);
        Date end = parse(date2);

        if (end < start) {
            swap(end, start);
        }

        int ans = 0;
        bool moved = false;
        if (start[0] < end[0]) {
            ans += finish_the_year(start);
            moved = true;
            start[0]++;
        }

        for (int year = start[0]; year < end[0]; year++) {
            ans += YEARS;
            ans += int(is_leap(year));
            moved = true;
        }

        if (moved) {
            start[0] = end[0];
            start[1] = start[2] = 1;
        }

        int d = start[2];
        for (int m = start[1]; m < end[1]; m++) {
            ans += DPM[m] - d + 1;
            if (m == 2) {
                ans += int(is_leap(start[0]));
            }
            d = 1;
        }
        ans += end[2] - d;
        return ans;
    }
};

// ~ JustJie