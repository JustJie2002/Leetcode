/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.31.2024 23:16:51
*********************************************/

using i64 = long long;

class DataStream {
public:
    queue<int> q, bad;
    int v, k;
    int cnt = 0;
    DataStream(int _v, int _k): v(_v), k(_k) {}
    
    bool consec(int x) {
        q.push(x);
        if (x != v) {
            cnt++;
            bad.push(1);
        } else {
            bad.push(0);
        }
        if (q.size() > k) {
            q.pop();
            cnt -= bad.front();
            bad.pop();
        }
        return q.size() == k && cnt == 0;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

// ~ JustJie