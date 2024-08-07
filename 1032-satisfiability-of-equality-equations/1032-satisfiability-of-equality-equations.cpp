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
    bool equationsPossible(vector<string>& equations) {
        //parent and rank initilization
	    rank.resize(26, 0);
        parent.resize(26);
        
        for (int i = 0; i < 26; ++i)
        {
            parent[i] = i;
        }
        
        //union of equal chars
        for(string &s: equations)
        {
            if(s[1] == '=') //a==b
            {
                unionSet(s[0]-'a', s[3]-'a');
            }
        }

        //not equal cases
        for(string &s: equations)
        {
            if(s[1] == '!') //a!=b
            {
                int parent_of_first = find(s[0]-'a');
                int parent_of_second = find(s[3]-'a');

                if(parent_of_first == parent_of_second)
                    return false;
            }
        }
        return true;
    }
};