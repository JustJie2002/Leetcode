/**
 * 
 * n is the # of rows in the cinema
 * reservedSeats are the seats that are reserved in the format of [row, col]
 * we need to find the total # of 4-person group that can fit in the cinema
 * 
 * Observations:
 * - Each row can have at most two 4-person groups
 *      - that is because we can fit a 4-person group from col 2 - 5 and 6 - 9
 * - There is only 3 ways for a 4-person group to fit
 *      - From column 2 to 5 (left of the row, split at left aisle)
 *      - From column 4 to 7 (middle of the row)
 *      - From column 6 to 9 (right of the row, split at right aisle)
 * - If a row is not reserved in any of its column we can just assume that it fits 2 groups
 * 
 * Approach:
 * - Use a map or unordered_map (since we don't care about the order of the row)
 *   to store the seats that are reserved where the key of the map being the row
 * - The size of the map would now be the # of rows for which have not been reserved.
 *   Therefore, we can say that # of unreserved rows = n - size of map and times 2
 *   to get the # of seats for the unreserved rows
 * - We iterate over the map and simulate the three possibilities that I've mentioned
 * - We consider two senarios:
 *      - if left side and right side are free then we have say that we can fit 2 groups here
 *      - otherwise, as long as any of the side is free we can say we can fit 1 group here
 * - We now can just return the ans 
 **/


class Solution {
public:
    bool check(bitset<11> seats, int a, int b) {
        int good = true;
        for (int i = a; i <= b; i++) {
            good &= (seats[i] == 0);
        }
        return good;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> taken;
        
        for (const auto& v : reservedSeats) {
            taken[v[0]].push_back(v[1]);
        }

        int unreserved = n - taken.size();
        int ans = unreserved * 2;

        for (const auto& [_, v] : taken) {
            bitset<11> seats;
            seats.reset();
            for (const auto& i : v) seats[i] = 1;
            bool left = check(seats, 2, 5);
            bool mid = check(seats, 4, 7);
            bool right = check(seats, 6, 9);
            if (left && right) {
                ans += 2;
            } else if (mid || left || right) {
                ans += 1;
            }
        }

        return ans;
    }
};