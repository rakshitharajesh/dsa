#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>>left_pq, right_pq;
        long long ans = 0;
        int next_left = 0;
        int next_right = n - 1;
        while(k > 0){
            // keep filling the left priority queue until it has candidate elements
            while(next_left <= next_right && left_pq.size() < candidates){
                left_pq.push(costs[next_left++]);
            }
            // keep filling the right priority queue until it has candidate elements
            while(next_right >= next_left && right_pq.size() < candidates){
                right_pq.push(costs[next_right--]);
            }
            // at this point, we know that both the left and the right 
            // priority queues have candidate elements
            // if not, next left has crossed enxt right
            // so we have evalauted all the elements in the array
            int left_min = left_pq.empty() ? INT_MAX : left_pq.top();
            int right_min = right_pq.empty() ? INT_MAX : right_pq.top();

            if(left_min <= right_min){
                ans += left_min;
                left_pq.pop();
            }else{
                
                ans += right_min;
                right_pq.pop();
            }k--;
        }
        return ans;
    }
};