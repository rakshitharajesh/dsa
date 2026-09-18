#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // max heap that holds the frequency of a particular task
        priority_queue<int>pq;
        // holds the frequency of a task, along with the next
        // time when that task can be used next
        queue<pair<int, int>>q;
        int time = 0;
        // store the frequency of each character
        vector<int>freq(26, 0);
        for(char task : tasks){
            freq[task - 'A']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] != 0)
                pq.push(freq[i]);
        }
        while(!pq.empty() || !q.empty()){
            time++;
            while(!q.empty() && q.front().second <= time){
                pq.push(q.front().first);
                q.pop();
            }
            if(pq.empty()) // idle time
                continue;
            int curr = pq.top();pq.pop();
            if(curr != 1){
                q.push({curr - 1, time + n + 1});
            }
        }
        return time;
    }
};