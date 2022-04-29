using i64 = long long;

class Solution {
public:
    string fractionToDecimal(i64 n, i64 d) {
        if (n == 0) return "0";
        string res;
        if ((n < 0) != (d < 0)) res += "-";
        n = abs(n), d = abs(d);
        res += to_string(n / d);
        if (n % d == 0) return res;
        res += '.';
        unordered_map<int, int> seen;
        for (i64 r = n % d; r; r %= d) {
            if (seen.count(r)) {
                res.insert(seen[r], 1, '(');
                res += ')';
                break;
            }
            seen[r] = res.size();
            r *= 10;
            res += to_string(r / d);
        }
        return res;
    }
};