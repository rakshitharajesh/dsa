#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // sort the events based on the start time
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        // keep extracting the event that ends the earliest
        // minheap - so we evaluate ALL the events ending before the current event
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int ans = 0;
        // max_prev stores the maximum possible value of the previou event
        // this works because we only consider 2 events 
        int max_prev = 0;
        for(const auto& ev : events){
            int s = ev[0];int e = ev[1];int v = ev[2];
            while(!pq.empty() && pq.top().first < s){
                max_prev = max(max_prev, pq.top().second);
                pq.pop();
            }
            // max prev has the previous event's value (max value)
            ans = max(ans, max_prev + v);
            pq.push({e, v}); 
        }
        return ans;
    }
};