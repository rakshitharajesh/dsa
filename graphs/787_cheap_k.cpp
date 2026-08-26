#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>graph(n);
        for(const auto& flight : flights){
            int u = flight[0];int v = flight[1];int w = flight[2];
            graph[u].push_back({v, w});
        }
        queue<pair<int, int>>q;
        q.push({0, src});

        int stops = 0;
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            int size = q.size();
            if(stops > k)  
                break;
            for(int i = 0 ; i < size ; i++){
                auto [d, curr] = q.front();q.pop();
                // we already found a better distance to get to the node
                
                for(const auto& [nb, edge] : graph[curr]){
                    if(dist[nb] > d + edge){
                        dist[nb] = edge + d;
                        q.push({dist[nb], nb});
                    }
                }
            }
            stops++;

        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};