package dp;
class Solution {
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int[][]dp = new int[n][n];
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = piles[i];
            for(int j = 0 ; j < n ; j++){
                
            }
        }
        //return compute(piles, 0, n - 1, dp) > 0;
        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = i ; j < n ; j++){
                dp[i][j] = piles[i] - dp[i + 1][j];
                if(j > 0)
                    dp[i][j] = Math.max(dp[i][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
    public int compute(int[]piles, int l, int r, int[][]dp){
        if(l == r)
            return piles[l];
        if(dp[l][r] != -1)
            return dp[l][r];
        int takeLeft = piles[l] - compute(piles, l + 1, r, dp);
        int takeRight = piles[r] - compute(piles, l , r - 1, dp);
        dp[l][r] = Math.max(takeLeft, takeRight);
        return dp[l][r];
    }
}