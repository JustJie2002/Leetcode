/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.06.2024 23:49:06
*********************************************/

using i64 = long long;

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

bool operator<(const Interval& a, const Interval& b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> all_times;
        for (const auto& work_time : schedule) {
            for (const auto& time : work_time) {
                all_times.push_back(time);
            }
        }

        sort(all_times.begin(), all_times.end());

        int n = all_times.size();
        int ptr = 0;
        auto get = [&]() {
            return all_times[ptr++];
        };

        vector<Interval> ans;
        auto cur = get();
        while (ptr < n) {
            auto nei = get();
            if (cur.end >= nei.start) {
                cur.end = max(cur.end, nei.end);
            } else {
                ans.emplace_back(cur.end, nei.start);
                cur = nei;
            }
        }

        return ans;
    }
};

// ~ JustJie