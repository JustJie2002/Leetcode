/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.27.2024 02:57:18
*********************************************/

using i64 = long long;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        auto get = [&](const auto& time) -> int {
            int hour, minute;
            sscanf(time.c_str(), "%d:%d", &hour, &minute);
            return hour * 60 + minute;
        };
        auto convert = [&](const auto& event) -> pair<int, int> {
            return make_pair(get(event[0]), get(event[1]));
        };

        const auto& [s1, e1] = convert(event1);
        const auto& [s2, e2] = convert(event2);

        int ms = max(s1, s2);
        int me = min(e1, e2);

        return ms <= me;
    }
};

// ~ JustJie