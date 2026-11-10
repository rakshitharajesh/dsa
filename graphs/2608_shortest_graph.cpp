#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);
        for(auto const& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int minPath = INT_MAX;
        for(int s = 0 ; s < n ; s++){
            queue<int>q;
            vector<int>dist(n, -1), parent(n, -1);
            parent[s] = s;
            dist[s] = 0;
            q.push(s);
        
            while(!q.empty()){
                int top = q.front();q.pop();
                for(int nb : adjList[top]){
                    if(dist[nb] == -1){
                        // first time visiting a node
                        dist[nb] = dist[top] + 1;
                        parent[nb] = top;
                        q.push(nb);
                    }else if(nb != parent[top]){
                        // we are not going back to the parent of top
                        minPath = min(minPath, dist[top] + dist[nb] + 1);
                    }
                }
            }
        }
        return minPath == INT_MAX ? -1 : minPath;
    }
};