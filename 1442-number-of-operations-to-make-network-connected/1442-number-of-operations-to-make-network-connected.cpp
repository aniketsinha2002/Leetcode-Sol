class Solution {
    // FIND UNION BY RANK WITH PATH COMPRESSION
    //parent of each nodes stored in parent array
    //if rank equal -> make any one parent and uska rank do +1
    //else jiska rank jyada hoga wo PAPA banega 0_0
    
    vector<int> rank;
    vector<int> parent;
    
    int find(int x)
    {
        if(x == parent[x])
            return x;
            
        int top_parent = find(parent[x]);
        
        //while comming back from recursion -> update the parent what we got from top
        //path compression
        parent[x] = top_parent;
        
        return parent[x];
    }
    
    //find the parent of x and y and if both are not in same set we can merge them
    void unionSet(int x,int y)
    {
    	int parent_x = find(x);
    	int parent_y = find(y);
    	
    	
    	if(parent_x == parent_y)
    	    return ;
    	    
    	if(rank[parent_x] > rank[parent_y])
    	{
    	    parent[parent_y] = parent_x;
    	}
    	else if(rank[parent_x] < rank[parent_y])
    	{
    	    parent[parent_x] = parent_y;
    	}
    	else //if equal
    	{
    	    parent[parent_x] = parent_y;
    	    rank[parent_y] ++;
    	}
    }
    
    public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //parent and rank initilization
        rank.resize(n, 0);
        parent.resize(n);
        
        int redundantEdges = 0;

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }

        int components = n;
        int edges = connections.size();

        // ideally components - 1 =< edges  means  for 2 components -> atleast 1 edge needed

        if(edges < components-1) return -1; //if 3 components 1 edges given

        for(auto &i: connections)
        {
            int parent_of_cable1 = find(i[0]);
            int parent_of_cable2 = find(i[1]);

            if(parent_of_cable1 == parent_of_cable2)
                redundantEdges++;
            else
            {
                unionSet(i[0], i[1]);
                components--;
            }
        }

        //check if remaining components can be interconnected with reductantCables
        // 2 components we need 1 cable
        if(components - 1 <= redundantEdges)
            return min(components - 1, redundantEdges);

        return -1;
    }
};