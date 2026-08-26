#include <vector>
#include <algorithm>
using namespace std;
class DSU{
public:
    int n;
    int count = 0;
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        this -> n = n;
        parent.resize(n);
        rank.resize(n);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool Union(int x, int y){
        int x_anc = find(x);
        int y_anc = find(y);
        
        if(x_anc == y_anc)
            return false;
        count++;
        if(rank[x_anc] > rank[y_anc]){
            parent[y_anc] = x_anc;
        }else if(rank[x_anc] < rank[y_anc]){
            parent[x_anc] = y_anc;
        }else{
            parent[y_anc] = x_anc;
            rank[x_anc]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0 ; i < edges.size() ; i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });

        // kruskals algo to find the mst weight;
        int mstWeight = 0;
        DSU dsu(n);
        for(const auto& edge : edges){
            int u = edge[0];int v = edge[1];int w = edge[2];
            if(!dsu.Union(u, v))
                continue;
            mstWeight += w;
        }
        vector<vector<int>>ans;
        vector<int>critical;
        vector<int>pseudo;
        // check if the edege being removed makes a difference 
        // to the newly calculated mst weight

        // critical edges - do not include each edge
        // check if the new mst has the same weight
        for(const auto& edge : edges){
            int weight = 0;
            DSU dsu2(n);
            int u = edge[0];int v = edge[1];
            int w = edge[2];int i = edge[3];
            int count = 0;
            for(const auto& e : edges){
                int u2 = e[0];int v2 = e[1];
                int w2 = e[2];int i2 = e[3];
                if(i2 == i)
                    continue;
                if(dsu2.Union(u2, v2)){
                    weight += w2;
                }
                    
            }
            if(weight != mstWeight || dsu2.count + 1 != n){
                critical.push_back(i);
                continue;
            }
            // the edge is NOT critical
            // we may check if it is pseudo critical
            DSU dsu3(n);
            // we include this edge
            dsu3.Union(u, v);
            int wt = w;
            for(const auto& e : edges){
                int u2 = e[0];int v2 = e[1];
                int w2 = e[2];int i2 = e[3];
                if(i2 == i)
                    continue;
                if(dsu3.Union(u2, v2)){
                    wt += w2;
                }
            }
            if(wt == mstWeight){
                pseudo.push_back(i);
            }
        }
        ans.push_back(critical);
        ans.push_back(pseudo);
        return ans;
    }
};