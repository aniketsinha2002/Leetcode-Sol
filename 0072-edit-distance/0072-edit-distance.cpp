class Solution {
public:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        // base case
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        // memoization
        if (dp[i][j] != -1)
            return dp[i][j];
        
        // main logic starts
        if (s1[i] == s2[j]) 
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);

        // delete, insert, replace
        return dp[i][j] = 1 + min(f(i - 1, j, s1, s2, dp), 
                                  min(f(i, j - 1, s1, s2, dp), 
                                      f(i - 1, j - 1, s1, s2, dp)));
    }

    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, str1, str2, dp);
    }
};
