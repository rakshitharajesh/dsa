#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int>kahnsTopoSort(vector<vector<int>>& adjList, vector<int>& indegree){
        queue<int>q;
        vector<int>ans;
        int n = indegree.size();
        for(int i = 1 ; i < n  ;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();q.pop();
            ans.push_back(curr);
            for(int nb : adjList[curr]){
                indegree[nb]--;
                if(indegree[nb] == 0){
                    q.push(nb);
                }
            }
        }
        if(ans.size() < n - 1) 
            return {};
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>ans(k, vector<int>(k, 0));

        vector<vector<int>>adjList(k + 1);
        vector<int>indegree(k + 1, 0);
        for(const auto& row : rowConditions){
            adjList[row[0]].push_back(row[1]);
            indegree[row[1]]++;
        }
        // sorted nodes 
        vector<int>rows = kahnsTopoSort(adjList, indegree);
        if(rows.empty())
            return {};

        // new adjList for the columns
        adjList.assign(k + 1, {});
        indegree.assign(k + 1, 0);
        for(const auto& col : colConditions){
            adjList[col[0]].push_back(col[1]);
            indegree[col[1]]++;
        }
        // sorted nodes for columns
        vector<int>cols = kahnsTopoSort(adjList, indegree);
        if(cols.empty())return {};
        unordered_map<int, int>colMap;

        // val -> map to column where it is present
        for(int i = 0 ; i < cols.size() ; i++){
            colMap[cols[i]] = i;
        }
        

        for(int i = 0 ; i < rows.size() ; i++){
            ans[i][colMap[rows[i]]] = rows[i];
        }
        return ans;
        
    }
};