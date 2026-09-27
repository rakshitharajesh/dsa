#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {        
        int n = points.size();

        int spanningTree = 0;
         
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;

        // unordered_set<int>visited;
        vector<bool>visited(n, false);
        pq.push({0, 0});

        while(!pq.empty()){
            auto [w, x] = pq.top();pq.pop();
           
            if(visited[x])
                continue;
            visited[x] = true;
            spanningTree += w;

            for(int i = 0 ; i < n ; i++){
                if(i == x || visited[i])continue;
                pq.push({abs(points[x][0] - points[i][0]) + abs(points[x][1] - points[i][1]), i});
            }
        }
        return spanningTree;
    }
};