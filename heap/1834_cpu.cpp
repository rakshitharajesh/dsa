#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int>ans;
        int index = 0;
        long long time = 0;
        // sorted in order of enqueue time
        vector<array<int, 3>>sorted(n);
        for(int i = 0 ; i < n ; i++){
            sorted[i] = {tasks[i][0], tasks[i][1], i};
        }
        sort(sorted.begin(), sorted.end());
        // {processing time, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        while(index < n || !pq.empty()){
            // cpu idle time
            while(pq.empty() && time < sorted[index][0]){
                time = sorted[index][0];
            }
            // enqueue all the tasks that can come next
            while(index < n && sorted[index][0] <= time){
                pq.push({sorted[index][1], sorted[index][2]});
                index++;
            }
            auto [proc, i] = pq.top();pq.pop();
            ans.push_back(i);
            time += proc;
        }
        return ans;
    }
};