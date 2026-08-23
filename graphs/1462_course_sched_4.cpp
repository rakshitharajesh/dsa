#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // floyd warshall O(n3) solution
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries){
            vector<vector<bool>>isPrerequisite(numCourses, vector<bool>(numCourses, false));
            for(const auto& p : prerequisites){
                isPrerequisite[p[0]][p[1]] = true   ;
            }
            for(int i = 0 ; i < numCourses ; i++){
                for(int j = 0 ; j < numCourses ; j++){
                    for(int k = 0 ; k < numCourses ; k++){
                        if(isPrerequisite[i][j] && isPrerequisite[j][k])
                            isPrerequisite[i][k] = true;
                    }
                }
            }
            vector<bool>ans;
            for(const auto& q : queries){
                if(isPrerequisite[q[0]][q[1]])
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
            return ans;
    }
// O(VE + Q) dfs based solution
    vector<bool> checkIfPrerequisite_(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>>prerequisite(numCourses);
        vector<vector<int>>adjList(numCourses);
        vector<bool>visited(numCourses, false);
        // fill out the adjacency list
        for(const auto& p : prerequisites){
            int a = p[0];int b = p[1];
            adjList[a].push_back(b);
        }   
        int n = queries.size();
        vector<bool>ans(n);
        for(int i = 0 ; i < n ; i++){
            dfs(queries[i][0], adjList, prerequisite, visited);
            if(prerequisite[queries[i][0]].count(queries[i][1]))
                ans[i] = true;
            else
                ans[i] = false;
        }
        return ans;
    }
    void dfs(int u, vector<vector<int>>& adjList, vector<unordered_set<int>>& prerequisite, vector<bool>& visited){
        if(visited[u]){
            return;
        }
        // we can mark the node as viisted before processing 
        // this is ok, because we know that the graph is a dag
        // this means that the node will not be encountered more than once in the same dfs call
        visited[u] = true;
        unordered_set<int>set;
        for(int nb : adjList[u]){
            set.insert(nb);
            dfs(nb, adjList, prerequisite, visited);
            unordered_set<int>nbset = prerequisite[nb];
            set.insert(nbset.begin(), nbset.end());
        }
        prerequisite[u] = set;
    }
    
};