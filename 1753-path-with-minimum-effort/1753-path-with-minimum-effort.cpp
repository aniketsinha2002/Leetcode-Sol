class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{-1,0},{0,-1},{0,1},{1, 0}};
    
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size(); //rows [[1,2],[1,3],[2,4]] 3 rows
        int m = heights[0].size(); //cols [[1,2],[1,3],[2,4]] 2 cols
        
        auto isSafe = [&](int x, int y) 
        {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, {0, 0}}); // diff x y
        result[0][0] = 0;
  
        while(!pq.empty()) 
        {
            int diff  = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            int x = node.first;
            int y = node.second;
            
            // Returning because no other path will provide a smaller effort.
            if (x == n-1 && y == m-1)
                return diff;
            
            for (auto dir : directions) 
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_)) 
                {
                    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
                    if (result[x_][y_] > newDiff)
                    {
                        result[x_][y_] = newDiff;
                        pq.push({result[x_][y_], {x_, y_}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};
