#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // create an adjacency list
        if(n == 1)
            return {0};
        vector<vector<int>>adjList(n); 
        vector<int>degree(n, 0);
        for(const auto& e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
            degree[e[0]]++;degree[e[1]]++;
        }
        queue<int>q;
        for(int i = 0 ; i < n ; i++){
            if(degree[i] == 1)
                q.push(i);
        }
        int remaining = n;
        while(remaining > 2){
            int leaves = q.size();
            remaining -= leaves;
            for(int i = 0 ; i < leaves ; i++){
                int node = q.front();q.pop();
                for(int nb : adjList[node]){
                    degree[nb]--;
                    if(degree[nb] == 1)
                        q.push(nb);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node);
        }
        return ans; 
    }
};