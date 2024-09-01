class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
    {
        //base case
        if(i>=s1.size() || j>=s2.size())
            return 0;

        if(dp[i][j] != -1) return dp[i][j];

        //main logic
        int ans =0;

        if(s1[i] == s2[j]) {
            ans = 1 + solve(s1, s2, i+1, j+1, dp);
        }
        else {
            return dp[i][j] = max(solve(s1,s2, i, j+1, dp), solve(s1,s2, i+1, j, dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return solve(s1,s2,0,0, dp);
    }
};