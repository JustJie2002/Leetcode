class ATM {
private:
    vector<long long> bank;
    const vector<int> convert = {20, 50, 100, 200, 500};
public:
    ATM() {
        bank.resize(5);
        for (int i = 0; i < 5; i++) {
            bank[i] = 0;
        }
    }
    
    void deposit(vector<int> c) {
        for (int i = 0; i < 5; i++) {
            bank[i] += c[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        int u = amount;
        vector<int> ans(5);

        for (int i = 4; ~i; i--) {
            int take = min<long long>(bank[i], u / convert[i]);
            u -= take * convert[i];
            ans[i] = take;
        }

        if (u) return {-1};

        for (int i = 0; i < 5; i++) bank[i] -= ans[i];
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */