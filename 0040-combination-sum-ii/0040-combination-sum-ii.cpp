class Solution {
public:
    void recursion(int ind, int target, vector<int>& tmp, int n, vector<vector<int>>& ans, vector<int>& nums)
    {
           //tc- 2^n log N
           //base cases
            if(target==0) {
                ans.push_back(tmp);
                return;
            }
        
        for(int i=ind; i<n;i++)
        {
            if(i>ind && nums[i] == nums[i-1]) continue;
            if(nums[i]>target) break;
            tmp.push_back(nums[i]);
            recursion(i+1, target-nums[i], tmp, n, ans, nums);
            tmp.pop_back(); 
        }       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = candidates.size();  
        sort(candidates.begin(), candidates.end());
        recursion(0, target, tmp, n, ans, candidates);
        return ans;
    }
};