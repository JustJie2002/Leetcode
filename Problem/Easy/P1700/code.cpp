/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.07.2024 22:32:21
*********************************************/

using i64 = long long;

class Solution {
public:
    template <int A>
    array<int, A> make(const auto& a) {
        array<int, A> cnt {};
        for (int x : a) {
            assert(x <= A);
            cnt[x]++;
        }
        return cnt;
    }

    int countStudents(vector<int>& peeps, vector<int>& food) {
        int n = peeps.size();
        auto cnt = make<2>(peeps);
        for (int i = 0; i < n; i++) {
            int x = food[i];
            if (!cnt[x]) {
                return n - i;
            }
            cnt[x]--;
        }

        return 0;
    }
};

// ~ JustJie