#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m;
    int n;
    int MOD = 1e9 + 7;
    int uniquePaths(vector<vector<int>>&grid){
        this -> m = grid.size();
        this -> n = grid[0].size();
        vector<vector<vector<int>>>dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
        // dp[i][j][0] => ways to reach(m - 1, n - 1) when we came from (i, j - 1)
        // dp[i][j][1] => ways to reach (m - 1, n - 1) when we came from (i + 1, j)
        dp[m - 1][n - 1][0] = 1;
        dp[m - 1][n - 1][1] = 1;
        for(int i = m - 1 ; i >= 0 ; i--){
            for(int j = n - 1 ; j >= 0 ; j--){
                if(i == m - 1 && j == n - 1)
                    continue;
                if(grid[i][j] == 0){
                    // does not matter how we reached (i, j) (from top or left cell)
                    int ways = (dp[i][j + 1][0] + dp[i + 1][j][1]) % MOD;
                    dp[i][j][0] = dp[i][j][1] = ways;
                }else{
                    // this is a mirror
                    dp[i][j][0] = dp[i + 1][j][1];
                    dp[i][j][1] = dp[i][j + 1][0];
                }
            }
        }
        return dp[0][0][0];
    }
    int uniquePaths_(vector<vector<int>>& grid) {
        this -> m = grid.size();
        this -> n = grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
        // dp[i][j][1] -> going down
        // dp[i][j][0] -> going right
        return solve(0, 0, 0, grid, dp);
    }
    int solve(int i, int j, int d,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(i == m - 1 && j == n - 1)
            return 1;
        if(i >= m || j >= n)
            return 0;
        if(dp[i][j][d] != -1)   
            return dp[i][j][d];
        if(grid[i][j] == 0){
            // move right and left
            int right = solve(i, j + 1, 0, grid, dp);
            int down = solve(i + 1, j, 1, grid, dp);
            return dp[i][j][d] = (right + down) % MOD;
        }else{
            if(d == 0){
                return dp[i][j][d] = solve(i + 1, j, 1, grid, dp);
            }
            return dp[i][j][d] = solve(i, j + 1, 0, grid, dp);
        }
        return -1;
    }
    
};