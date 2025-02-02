class Solution {
public:
    int solve(int n, vector<int>& dp)
    {
        if(n<0)
            return 0;

        if(n==0 )
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int ans=0;

        if(n-1>=0)
            ans += solve(n-1, dp);
        if(n-2>=0)
            ans += solve(n-2, dp);

        return dp[n] = ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};