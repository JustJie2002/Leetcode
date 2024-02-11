/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.08.2024 14:20:59
*********************************************/

using i64 = long long;

// Approach 1: Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] + a[j] == target) {
                    return {i, j};
                }
            }
        }

        assert(0);
    }
};

// Approach 2: Hash Map
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();

        unordered_map<int, int> prv_seen;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] + a[j] == target) {
                    return {i, j};
                }
            }
        }

        assert(0);
    }
};

// ~ JustJie