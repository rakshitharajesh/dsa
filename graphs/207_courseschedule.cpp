#include <bits/stdc++.h>
class Solution {
public:
    // topological sort : Kahn's algorithm
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>>adjList(numCourses);
        vector<int>indegree(numCourses, 0);
        // building the adjacency list
        for(const auto& p : prerequisites){
            int a = p[0];int b = p[1];
            adjList[a].push_back(b);
            indegree[b]++;
        }
        queue<int>q;
        int visited = 0;
        // push all the nodes with indegree = 0 into the q
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();q.pop();
            visited++;
            for(int nb : adjList[node]){
                // decrement the indegree of each neighbour 
                indegree[nb]--;
                if(indegree[nb] == 0)
                    q.push(nb);
            }
        }
        return visited == numCourses;
    }
    // dfs
    bool canFinish_(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>visited(numCourses + 1, false);
        vector<vector<int>>adjList(numCourses + 1);
        // building the adjacency list
        for(const auto& p : prerequisites){
            int a = p[0];int b = p[1];
            adjList[a].push_back(b);
        }
        for(int i = 0 ; i <= numCourses ; i++){
            vector<bool>recStack(numCourses + 1, false);
            if(!visited[i])
                if(cycle(i, adjList, recStack, visited))
                    return false;
        }
        return true;
    }
    bool cycle(int u, vector<vector<int>>& adjList, vector<bool>& recStack, vector<bool>& visited){
        // if the node is marked visited, then no edge from this node
        // is a part of a cycle
        if(visited[u])
            return false;
        // if the node has already been visited on this path
        // we just identified a cycle
        if(recStack[u])
            return true;
        recStack[u] = true;
        for(int nb : adjList[u]){
            if(cycle(nb, adjList, recStack, visited))
                return true;
        }
        visited[u] = true;
        return false;
    }
};