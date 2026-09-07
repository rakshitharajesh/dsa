#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // the cost of partitioning (i...j) together
    // we put a mailbox at the median
    int costs[100][100] = {};
    // dp[index][k] represents the minimum cost for k mail boxes until index
    int dp[100][100] = {};
    
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        memset(dp, -1, sizeof(dp));
        sort(houses.begin(), houses.end());
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                int medianPos = houses[(i + j) / 2];
                for(int m = i ; m <= j ; m++){
                    costs[i][j] += abs(houses[m] - medianPos);
                }
            }
        }
        return memo(houses, 0, k);
    }
    int memo(vector<int>& houses, int index, int k){
        int n = houses.size();
        if(k == 0 && index == n)
            return 0;
        if(k == 0 || index == n)
            return INT_MAX;
        if(dp[index][k] != -1)
            return dp[index][k];
        int ans = INT_MAX;
        for(int j = index ; j < houses.size() ; j++){
            int nextCost = memo(houses, j + 1, k - 1);
            if(nextCost != INT_MAX)
                ans = min(ans, costs[index][j] + nextCost);
        }
        return dp[index][k] = ans;
    }
};