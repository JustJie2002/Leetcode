#define sz(a) int(a.size())

class Solution {
public:
    string digitSum(string s, int k) {
        string sb = s;
        
        auto f = [&](string word) -> string {
            int sum = 0;
            for (auto& c : word) sum += (c - '0');
            return to_string(sum);
        };

        while (sz(sb) > k) {
            string nsb;

            for (int i = 0; i < sz(sb); i += k) {
                string part = sb.substr(i, k);
                nsb += f(part);
            }

            swap(nsb, sb);
        }

        return sb;
    }
};