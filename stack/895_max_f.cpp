#include <bits/stdc++.h>
using namespace std;
class FreqStack {
public:
    int mostFrequent = 0;
    // frequency -> map to a stack 
    unordered_map<int, stack<int>>map;
    // frequency of each element
    unordered_map<int, int>freq;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val] = freq[val] + 1;
        map[freq[val]].push(val);
        mostFrequent = max(mostFrequent, freq[val]);
    }
    
    int pop() {
        if(mostFrequent == 0)
            return -1;
        int popped = map[mostFrequent].top();map[mostFrequent].pop();
        freq[popped]--;
        if(map[freq[popped] + 1].empty())
            mostFrequent = freq[popped];

        return popped;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */