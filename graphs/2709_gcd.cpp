#include <bits/stdc++.h>
using namespace std;
class DSU{
public:
    unordered_map<int, int>rank;
    unordered_map<int, int>parent;
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int a, int b){
        int x = find(a);int y = find(b);
        if(x == y)
            return false;
        if(rank[x] > rank[y]){
            parent[y] = x;
        }else if(rank[y] > rank[x]){
            parent[x] = y;
        }else{
            rank[x]++;
            parent[y] = x;
        }
        return true;
    }
};

class Solution {
public:
    vector<int>getPrimeFactors(int num){
        vector<int>ans;
        if(num % 2 == 0){
            ans.push_back(2);
            while(num % 2 == 0)
                num /= 2;
        }
        // O(n ^ 0.5)
        for(int i = 3 ; i * i <= num ; i++){
            if(num % i == 0){
                ans.push_back(i);
                while(num % i == 0){
                    num /= i;
                }
            } 
        }
        if(num > 2){
            ans.push_back(num);
        }
        return ans;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        DSU dsu;
        int components = 0;
        if(nums.size() == 1)
            return true;
        // adding prime factors as vertices
        for(int num : nums){
            if(num == 1)
                return false;
            vector<int>prime = getPrimeFactors(num);
            for(int p : prime){
                if(!dsu.parent.count(p)){
                    dsu.parent[p] = p;
                    dsu.rank[p] = 0;
                    components++;
                }
            }
            for(int i = 1 ; i < prime.size(); i++){
                if(dsu.Union(prime[i - 1], prime[i]))
                    components--;
            }
        }
        return components == 1;
    }
};