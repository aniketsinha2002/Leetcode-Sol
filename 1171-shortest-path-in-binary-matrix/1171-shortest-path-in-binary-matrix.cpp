class Solution {
    vector<vector<int>> directions{{1, 1},  {0, 1},   {1, 0},  {-1, 0},
                                   {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    bool isSafe(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();    // number of rows
        int n = grid[0].size(); // number of columns

        if (m == 0 || n == 0 || grid[0][0] != 0) {
            return -1;
        }

        // BFS
        queue<pair<int, int>> q;
        q.push({0, 0});  // starting point
        grid[0][0] = 1;  // mark visited 

        int level = 0;

        while (!q.empty()) {
            int N = q.size();

            while (N--) {  // iterate over the current level
                pair<int, int> top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;

                // return if we reach the bottom-right corner
                if (x == m - 1 && y == n - 1) {
                    return level + 1;  // the number of steps taken
                }

                // explore all 8 directions
                for (auto& dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (isSafe(x_, y_, m, n) && grid[x_][y_] != 1) {
                        q.push({x_, y_});
                        grid[x_][y_] = 1;  // mark as visited
                    }
                }
            }
            level ++;
        }
        return -1;
    }
};