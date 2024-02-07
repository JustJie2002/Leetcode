/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.06.2024 21:49:45
*********************************************/

using i64 = long long;

class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();

        vector<int> Lpos, Rpos;
        for (int i = 0; i < n; i++) {
            if (dom[i] == 'L') {
                Lpos.push_back(i);
            }
            if (dom[i] == 'R') {
                Rpos.push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (dom[i] == '.') {
                int L = -1, R = -1;
                auto it = lower_bound(Lpos.begin(), Lpos.end(), i);
                auto it2 = lower_bound(Rpos.begin(), Rpos.end(), i);
                if (it != Lpos.end()) {
                    L = *it;
                    if (it2 != Rpos.end() && *it2 < L) {
                        L = -1;
                    }
                }
                if (it2 != Rpos.begin()) {
                    R = *prev(it2);
                    if (it != Lpos.begin() && R < *prev(it)) {
                        R = -1;
                    }
                }

                if (L != -1 && R != -1) {
                    int Ldis = L - i;
                    int Rdis = i - R;
                    if (Ldis < Rdis) {
                        dom[i] = 'L';
                    } else if (Rdis < Ldis) {
                        dom[i] = 'R';
                    }
                } else if (L != -1) {
                    dom[i] = 'L';
                } else if (R != -1) {
                    dom[i] = 'R';
                }
            }
        }

        return dom;
    }
};

// ~ JustJie