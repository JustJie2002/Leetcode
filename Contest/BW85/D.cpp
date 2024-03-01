/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.01.2024 10:12:05
*********************************************/

using i64 = long long;

struct DSU {
    vector<int> par, siz;
    vector<i64> sum;
    int components;

    DSU() {}
    DSU(int n): components(n) {
        init(n);
    }

    void init(int n) {
        par.resize(n);
        sum.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        sum[x] += sum[y];
        par[y] = x;
        components--;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }

    i64 get_sum(int x) {
        return sum[find(x)];
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& a, vector<int>& queries) {
        int n = a.size();

        vector<i64> answer(n);
        vector<bool> exist(n);
        exist[queries.back()] = true;
        DSU uf(n);
        for (int i = 0; i < n; i++) {
            uf.sum[i] = a[i];
        }

        i64 res = a[queries.back()];
        for (int i = n - 2; i >= 0; i--) {
            answer[i] = res;
            int j = queries[i];

            if (j > 0 && exist[j - 1]) {
                uf.merge(j, j - 1);
            }
            if (j < n - 1 && exist[j + 1]) {
                uf.merge(j, j + 1);
            }

            res = max(res, uf.get_sum(j));
            exist[queries[i]] = true;
        }

        return answer;
    }
};

// ~ JustJie