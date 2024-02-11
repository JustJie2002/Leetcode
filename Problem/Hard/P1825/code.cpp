/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.31.2024 09:39:13
*********************************************/

using i64 = long long;


template <class Info>
struct KWindow {
    multiset<Info> s;
    int k;
    Info res = {0};
    typename multiset<Info>::iterator it;

    KWindow() {}
    KWindow(int _k) : k(_k) {}

    void add(const Info& x) {
        s.insert(x);
        if (s.size() <= k) res += x;
        else if (x < *it) res += x - *(it--);
        if (s.size() == k) it = prev(s.end());
    }

    void erase(const Info& info) {
        if (s.size() <= k) {
            s.erase(s.lower_bound(info));
            res -= info;
        }
        else {
            auto it2 = s.lower_bound(info);
            if (!(*it < info)) {
                res += *(++it) - info;
            }
            s.erase(it2);
        } 
    }

    Info get() { return res; }
};

struct Info {
    int x;
    Info(): x(0) {}
    Info(int _x): x(_x) {}
    bool operator<(Info& rhs) {
        return x < rhs.x;
    }
    Info operator+=(const Info& rhs) {
        x += rhs.x;
        return *this;
    }
};

Info operator+(const Info& a, const Info& b) {
    return {a.x + b.x};
}

Info operator-(const Info& a, const Info& b) {
    return {a.x - b.x};
}

class MKAverage {
public:
    KWindow<Info> small;
    KWindow<Info> big;
    int M;
    deque<int> values;
    long long total;

    MKAverage(int m, int k) {
        small = KWindow<Info>(k);
        big = KWindow<Info>(k);
        total = 0;
        values.clear();
        M = m;
    }
    
    void addElement(int num) {
        total += num;
        values.push_back(num);
        small.insert(Info(num));
        big.insert(Info(num));
        if (values.size() > M) {
            small.erase(Info(values.front()));
            big.erase(Info(values.front()));
            total -= values.front();
            values.pop_front();
        }
    }
    
    int calculateMKAverage() {
        if (values.size() < M) return -1;
        return (total - small.get().x - big.get().x) / (M - small.k * 2);
    }
};

// ~ JustJie