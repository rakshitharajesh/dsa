package dp;
import java.util.Arrays;
class Solution {
    public boolean predictTheWinner(int[] nums) {
        int aScore = 0;
        int bScore = 0;
        int n = nums.length;
        int[][]dp = new int[n][n];
        Arrays.stream(dp).forEach(row -> Arrays.fill(row, -1));
        return compute(nums, 0, n - 1, dp) >= 0;
    }

    // maximum possible difference in the score between a and b
    // when both players are playing optimally
    int compute(int[]nums, int l, int r, int[][]dp){
        if(l == r)
            return nums[l];
        if(dp[l][r] != -1)
            return dp[l][r];
        int pickLeft = nums[l] - compute(nums, l + 1, r, dp);
        int pickRight = nums[r] - compute(nums, l , r -1, dp);
        dp[l][r] = Math.max(pickLeft, pickRight);
        return dp[l][r];
    }
}