#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 1;
        }
        int start = 0;
        int maxLength = 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = i + 1 ; j < n ; j++){
                if(s[i] == s[j]){
                    if(dp[i + 1][j - 1] == 0 && j - i > 1)
                        continue;
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                    if(dp[i][j] > maxLength){
                        start = i;
                        maxLength = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};