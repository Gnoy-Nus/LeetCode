class Solution {
public:
    int climbStairs(int n) {
        int dp[n+2];
        dp[1]=1;
        dp[2]=2;
        for(int j=3;j<=n;j++)
        dp[j]=dp[j-1]+dp[j-2];
        return dp[n];
    }
};