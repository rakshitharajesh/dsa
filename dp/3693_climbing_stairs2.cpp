#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n, vector<int>& costs){
        int a = 0, b = INT_MAX / 2, c = INT_MAX / 2; // dp[i - 1], dp[i - 2], dp[i - 3]
        for(int i = 1 ; i <= n ; i++){
            int curr = min({a + 1, b + 4, c + 9}) + costs[i - 1];
            c = b;
            b = a;
            a = curr;
        }
        return a;

    }
    int climbStairs_(int n, vector<int>& costs) {
        vector<int>dp(n + 1, 0);
        dp[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            if(i == 1)
                dp[i] = costs[i - 1] + 1;
            else if(i == 2)
                dp[i] = min(dp[i - 1] + 1, dp[i - 2] + 4) + costs[i - 1];
            else
                dp[i] = min({dp[i - 1] + 1, dp[i - 2] + 4, dp[i - 3] + 9}) + costs[i - 1];
        }
        return dp[n];
    }
};