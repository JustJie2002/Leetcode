/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.28.2024 19:06:50
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        nums.push_back(nums.back()); // using this so we can append the last chunk of range without explicitly asking it to

        auto convert_range = [&](int s, int e) -> string {
            string range = to_string(nums[s]);
            if (s != e) {
                range += "->";
                range += to_string(nums[e]);
            }
            return range;
        };

        int start = 0;
        vector<string> ranges;
        for (int end = 1; end < nums.size(); end++) {
            if (nums[end - 1] == INT_MAX || nums[end] != nums[end - 1] + 1) {
                ranges.push_back(convert_range(start, end - 1));
                start = end;
            }
        }

        return ranges;
    }
};

// ~ JustJie