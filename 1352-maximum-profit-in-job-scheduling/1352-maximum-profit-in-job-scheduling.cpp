class Solution {
public:
    int getNextIdx(vector<vector<int>>& arr, int i)
    {
        int end = arr[i][1];
        i++;
        while (i < arr.size() && arr[i][0] < end) // first job whose start time is >= current job's end time
        {
            i++;
        }
        return i;
    }
    
    int solve(int i, vector<vector<int>>& arr, int n, vector<int>& dp)
    {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int profit = arr[i][2];
        int next = getNextIdx(arr, i); 

        int take = profit + solve(next, arr, n, dp);
        int notTake = solve(i + 1, arr, n, dp);  

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> arr(n, vector<int>(3, 0)); // Initialize vector of vectors

        for(int i = 0; i < n; i++)
        {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        // Sort jobs by start time
        sort(begin(arr), end(arr), [](auto& vec1, auto& vec2) {
            return vec1[0] < vec2[0];
        });

        vector<int> dp(n, -1); // To memoize results

        return solve(0, arr, n, dp);
    }
};
