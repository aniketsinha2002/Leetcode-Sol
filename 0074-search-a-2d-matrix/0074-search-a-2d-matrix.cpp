class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //col
        int s = 0;
        int e = m*n-1;

        while(s<=e)
        {
            int m = s+(e-s)/2;
            //row = mid / no of col
            //col = mid % no of col
            if(matrix[m/n][m%n] > target)
            {
                e=m-1;
            }
            else if(matrix[m/n][m%n] < target)
            {
                s=m+1;
            }
            else
                return true;
        }
        return false;
    }
};