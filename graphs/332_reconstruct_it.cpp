#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    unordered_map<string, multiset<string>>graph;
    vector<string>ans;

    // hierholzer's algorithm
    void dfs(string s){
        while(!graph[s].empty()){
            string v = *graph[s].begin();
            graph[s].erase(graph[s].begin());
            dfs(v);
        }
        ans.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(const auto& ticket : tickets){
            graph[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};