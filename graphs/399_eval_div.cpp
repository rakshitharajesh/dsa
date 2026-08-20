#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double dfs(unordered_map<string, unordered_map<string, double>>& adjList, string u, string v, unordered_set<string>& visited){
        if(!adjList.count(u) || !adjList.count(v))
            return -1;
        if(visited.count(u))
            return -1;
        visited.insert(u);
        if(u == v){
            // we have reached our destination
            return 1;
        }
        double weight = 1;
        for(const auto&[nb, weight] : adjList[u]){
            double dist = dfs(adjList, nb, v, visited);
            if(dist == -1)continue;
            return dist * weight;
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>>adjList;
        vector<double>ans;
        for(int i = 0 ; i < equations.size() ; i++){
            const auto& equation = equations[i];
            adjList[equation[0]][equation[1]] = values[i];
            adjList[equation[1]][equation[0]] = (double)1 / values[i];
        }
        for(const auto& query : queries){
            unordered_set<string>visited;
            double q = dfs(adjList, query[0], query[1], visited);
            ans.push_back(q);
        }
        return ans;
    }
};