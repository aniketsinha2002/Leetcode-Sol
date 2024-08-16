class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        while(start<end)
        {
            int mid = start + (end - start) / 2;

            //right side is even or not
            bool isEven = (end - mid) % 2 == 0;

            if(nums[mid] == nums[mid+1])
            {
                if(isEven)
                {
                    start = mid+2;
                }
                else
                    end = mid-1;
            }
            else //not equal
            {
                if(isEven)
                {
                    if(nums[mid]==nums[mid-1])
                    {
                        end = mid -2;
                    }
                    else
                        end = mid;
                }
                else
                    start = mid+1;
            }
        }

        return nums[end];
    }
};