class Solution {
public:
    int binarySearch(int s, int e, vector<int>& nums, int target)
    {
        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid]>target)
            {
                e=mid-1;
            }
            else if(nums[mid]<target)
            {
                s=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;

        while(s<e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid]>nums[e])
            {
                s=mid+1;
            }
            else
                e=mid;
        }

        int pivot_idx = s; //minimum element -> idx
        //searching in both sorted parts

        int leftPart = binarySearch(0,pivot_idx-1, nums, target);
        int rightPart = binarySearch(pivot_idx, nums.size()-1, nums, target);

        //cout<<pivot_idx<<leftPart<<rightPart<<endl;

        if(leftPart != -1)
            return leftPart;
        
        if(rightPart != -1)
            return rightPart;

        return -1;
    }
};