#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for(int i = 0 ; i < n ; i++)
            dp[i][i] = true;
        
        int ans = 0;

        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = i + 1 ; j < n ; j++){
                dp[i][j] = (s[i] == s[j]) && (j - i == 1 || dp[i + 1][j - 1]); 
                if(dp[i][j])    
                    ans++;
            }
        }
        return ans + n;
    }
};