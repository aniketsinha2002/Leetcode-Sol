class Solution {
public:
    void recursion(int ind, vector<int>& tmp, int n, vector<vector<int>>& ans, vector<int>& nums) {
        // Base case
         ans.push_back(tmp);
  

        for (int i = ind; i < n; i++) {
            // Skip duplicates
            if (i > ind && nums[i] == nums[i - 1]) continue;
            tmp.push_back(nums[i]);
            recursion(i + 1, tmp, n, ans, nums);
            tmp.pop_back();
        }
    }
    
    //tc - 2^n (recursion) * n (put into ans)
    //sc - O(2^n) (store 2^n subsets) * O(k) (everyone will be having avg length k) 
    //aux sc - O(n) (aux space of recursion call) 

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        recursion(0, tmp, n, ans, nums);
        return ans;
    }
};
