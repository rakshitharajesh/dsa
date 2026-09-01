#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>>workers;
        int n = quality.size();
        for(int i = 0 ; i < n ; i++){
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        // sort the workers based on the ratio - lower ratio first
        sort(workers.begin(), workers.end(), [](const pair<double, int>& a, const pair<double, int>& b){
            return a.first < b.first;
        });
        // we need the priority queue to store the quality
        priority_queue<int>pq;
        double res = DBL_MAX;
        int total_quality = 0;
        for(auto [rate, q] : workers){
            pq.push(q);
            total_quality += q;
            if(pq.size() > k){
                int top = pq.top();
                total_quality -= top;
                pq.pop();
            }
            if(pq.size() == k){
                res = min(res, total_quality * rate);
            }
        }
        return res;
    }
};