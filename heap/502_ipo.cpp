#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // current capital
        int curr_cap = w;

        int n = profits.size();
        vector<pair<int, int>>arr(n);
        for(int i = 0 ; i < n ; i++){
            arr[i] = {capital[i], profits[i]};
        }
        // max heap
        priority_queue<int>pq;
        sort(arr.begin(), arr.end());
        int index = 0;
    
        while(k > 0){
            // push all the candidates into the priority queue 
            while(index < n && arr[index].first <= curr_cap){
                pq.push(arr[index++].second);
            }
            // the queue has all the projects that can be taken now
            if(!pq.empty()){
                curr_cap += pq.top();pq.pop();k--;
            }else
                break;
        }
        return curr_cap;
    }
};