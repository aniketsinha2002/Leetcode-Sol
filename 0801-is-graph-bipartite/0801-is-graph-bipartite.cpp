class Solution {
public:
    bool BFS(vector<vector<int>>& adj, int u, vector<int>& colour, int currColour)
    {
        queue<int> q;

        q.push(u);
        colour[u] = currColour;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto& v: adj[u])
            {
                if(colour[v] == colour[u]) return false;
                
                if(colour[v] == -1)
                {
                    colour[v] = !colour[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //using bfs
        int n = graph.size();
        vector<int> colour(n, -1); // green -> 0, red -> 1
        int currColour = 0;

        for(int node=0; node<n; node++)
        {
            if(colour[node] == -1)
            {
                if(!BFS(graph, node, colour, currColour))
                    return false;
            }
        }
        return true;
    }
};