class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int source = k;

        // Create the adjacency list
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &it : times) {
            int u = it[0];
            int v = it[1];
            int t = it[2]; // weight -> time
            
            // u -> v, given directed edges
            adj[u].push_back({v, t});
        }

        // Min-heap for traversing
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Stores the distance from the source to the rest of the nodes (indexes)
        // result vector will store the distance of each node (as indexes) from the source in result[idx]
        vector<int> result(n + 1, INT_MAX);
        
        // Source to source distance when destination = source
        result[source] = 0;
        pq.push({0, source}); // distance, source

        while (!pq.empty()) {
            pair<int,int> top = pq.top();
            pq.pop();

            int dist = top.first;
            int u = top.second;
            
            for (auto &v : adj[u]) {
                int adjNode = v.first;
                int adjDist = v.second;
                
                // Distance between source to adjNode
                if (dist + adjDist < result[adjNode]) {
                    result[adjNode] = dist + adjDist;
                    pq.push({dist + adjDist, adjNode});
                }
            }            
        }

        // Finding the maximum time it will take to reach the farthest node
        int mx = -1;

        for (int i = 1; i <= n; i++) {
            if (result[i] == INT_MAX) {
                return -1;
            }
            mx = max(mx, result[i]);
        }

        return mx;
    }
};
