class Solution {
public:
    void bfs(vector<vector<int>>& adj, int u, vector<bool>& vis)
    {
        queue<int> q;

        vis[u] = 1;
        q.push(u);

         while(!q.empty())
         {
            int u = q.front();
            q.pop();

            for(auto &v : adj[u])
            {
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
         }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //creatong an adj list from adj matrix
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    //cout<<i<<"-->"<<j<<" ";
                    
                    adj[j].push_back(i);
                    //cout<<j<<"-->"<<i<<" "; 
                }
            }
        }

        //traversal - BFS
        vector<bool> vis(n);
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(adj, i, vis);
            }
        }

        return count;
    }
};