class CustomStack {
private:
    int maxSize;
    vector<int> st;

public:
    CustomStack(int _maxSize) {
        maxSize = _maxSize;
        st.clear();
    }
    
    void push(int x) {
        if (int(st.size()) < maxSize)
            st.push_back(x);
    }
    
    int pop() {
        if (st.empty())
            return -1;
        int last = st.back();
        st.pop_back();
        return last;
    }
    
    void increment(int k, int val) {
        int n = st.size();
        for (int i = 0; i < min(k, n); i++)
            st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */