/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.12.2024 22:07:51
*********************************************/

using i64 = long long;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int cap) {
        int n = buses.size(), m = passengers.size();

        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        vector<int> get_on(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && passengers[j] <= buses[i] && get_on[i] < cap) {
                get_on[i]++;
                j++;
            }
        }

        unordered_set<int> seen(passengers.begin(), passengers.end());

        int t;
        if (get_on.back() != cap) {
            t = buses.back();
        } else {
            t = passengers[j - 1] - 1;
        }
        while (seen.contains(t)) {
            t--;
        }

        return t;
    }
};

// ~ JustJie