class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jD, int n, int idx, int d)
    {
        //base case
        if(d==1)
        {
            int maxD = jD[idx];
            for(int i=idx; i<n; i++)
            {
                maxD = max(maxD, jD[i]);
            }
            return maxD;
        }

        if(t[idx][d] != -1)
            return t[idx][d];

        int maxD = jD[idx];
        int finalResult = INT_MAX;

        for(int i=idx; i<=n-d; i++)
        {
            maxD = max(maxD, jD[i]);

            int result = maxD + solve(jD, n, i+1, d-1);

            finalResult = min(finalResult, result);
        }
        return t[idx][d] = finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d) return -1;
        memset(t, -1, sizeof(t));
        return solve(jobDifficulty, n, 0, d);
    }
};