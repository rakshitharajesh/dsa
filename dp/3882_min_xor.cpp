#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    int K = 1024;
    int minCost(vector<vector<int>>& grid) {
        this -> m = grid.size();
        this -> n = grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(K, -1)));
        // move right or down
        return solve(dp, grid, 0, 0, 0);
    }
    int solve(vector<vector<vector<int>>>&dp, vector<vector<int>>&grid, int i, int j, int k){
        int curr = k ^ grid[i][j];
        if(i == m - 1 && j == n - 1)
            return curr;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        int right = j + 1 < n ? solve(dp, grid, i, j + 1, curr) : INT_MAX;
        int down = i + 1 < m ? solve(dp, grid, i + 1, j, curr) : INT_MAX;
        return dp[i][j][k] = min(right, down);
    }
};