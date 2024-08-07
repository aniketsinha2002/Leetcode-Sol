class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int u, vector<int>& colour, int currColour)
    {
        colour[u] = currColour; //green

        for(auto &v: adj[u])
        {
            if(colour[v] == currColour) // if its neighbour also green means visited and same colour
                return false;

            if(colour[v] == -1)
            {
                //dfs call
                bool ans = DFS(adj, v, colour, !currColour);

                //if in any point of time we encounter we cannot colour the way its required we will leave
                if(!ans) return false;         
            }
            //if its neighbour is red means ok but its already visited so skip
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n,-1); // 0 -> green, 1 -> red

        int currColour = 0;

        for(int node =0; node<n; node++)
        {
            if(colour[node] == -1)
            {
                if(!DFS(graph, node, colour, currColour))
                    return false;
            }
        }
        return true;
    }
};