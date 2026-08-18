class dsu{
    public:
    int n;
    vector<int>parent;
    vector<int>rank;
    dsu(int n){
        this -> n = n;
        parent.resize(n);
        rank.resize(n);
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
    }
    int find(int a){
        if(parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    bool Union(int a, int b){
        int x = find(a);int y = find(b);
        if(x == y)
            return true;    // they are already connected
        if(rank[x] > rank[y])
            parent[y] = parent[x];
        else if(rank[x] < rank[y])
            parent[x] = y;
        else{
            rank[x]++;
            parent[y] = x;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        dsu d(n + 1);
        for(const auto& e : edges){
            if(d.Union(e[0], e[1]))
                return e;
        }
        return {};
    }
};