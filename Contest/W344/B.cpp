/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.17.2024 00:52:04
*********************************************/

using i64 = long long;

class FrequencyTracker {
public:
    map<int, int> counter;
    map<int, int> freq;
    FrequencyTracker() {
        
    }
    
    void add(int x) {
        int p = counter[x]++;
        if (p > 0) {
            freq[p]--;
        }
        freq[p + 1]++;
    }
    
    void deleteOne(int x) {
        if (counter[x] == 0) {
            return;
        }
        int p = counter[x]--;
        if (p > 0) {
            freq[p]--;
        }
        if (p - 1 > 0) {
            freq[p - 1]++;
        }
    }
    
    bool hasFrequency(int f) {
        return freq[f] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

// ~ JustJie