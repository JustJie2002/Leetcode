/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.21.2024 12:04:02
*********************************************/

using i64 = long long;

class MKAverage {
public:
    int m, k;
    int n;
    vector<int> added_elements;
    multiset<int> lower, middle, upper;
    i64 res = 0;
    MKAverage(int _m, int _k): m(_m), k(_k), n(0) {}

    void remove(int x) {
        if (lower.contains(x)) {
            lower.erase(lower.find(x));
            auto it = middle.begin();
            lower.insert(*it);
            res -= *it;
            middle.erase(it);
        } else if (middle.contains(x)) {
            middle.erase(middle.find(x));
            res -= x;
        } else {
            upper.erase(upper.find(x));
            auto it = prev(middle.end());
            upper.insert(*it);
            res -= *it;
            middle.erase(it);
        }
    }

    void addElement(int x) {
        added_elements.push_back(x);
        lower.insert(x);
        if (lower.size() > k) {
            x = *prev(lower.end());
            lower.erase(lower.find(x));
            upper.insert(x);
            if (upper.size() > k) {
                x = *upper.begin();
                upper.erase(upper.find(x));
                middle.insert(x);
                res += x;
            }
        }
        n++;
        if (n > m) {
            remove(added_elements[n - m - 1]);
        }
    }
    
    int calculateMKAverage() {
        if (n < m) {
            return -1;
        }
        int siz = middle.size();
        assert(siz == m - 2 * k);
        assert(siz > 0);
        return res / siz;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

// ~ JustJie