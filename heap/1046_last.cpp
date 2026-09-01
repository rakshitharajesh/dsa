#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int s : stones)
            pq.push(s);
        while(pq.size() > 1){
            int s1 = pq.top();pq.pop();
            int s2 = pq.top();pq.pop();
            int next = abs(s1 - s2);
            if(next > 0)
                pq.push(next);
        }
        return pq.empty() ? 0 : pq.top();
    }
};