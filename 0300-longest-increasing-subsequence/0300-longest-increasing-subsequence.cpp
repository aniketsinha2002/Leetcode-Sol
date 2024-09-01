class Solution {
public:
    int solve(vector<int>& nums, int prev, int i, vector<vector<int>>& dp)
    {
        if(i>=nums.size())
            return 0;

        if(prev != -1 && dp[prev][i] != -1 )
            return dp[prev][i];

        int take=0, nottake =0;

        //generating all subsequences through take and not take, but keeping in mind the condition of Increasing
        if(prev == -1 || nums[prev] < nums[i])
                take = 1 + solve(nums, i, i+1, dp);
        
        nottake = 0 + solve(nums, prev, i+1, dp);

        //returning the max LIS comming from take and not take path
        return prev == -1 ? max(take,nottake) : dp[prev][i] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int i=0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(nums, prev, i, dp);
    }
};