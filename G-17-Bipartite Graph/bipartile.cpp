class Solution {
public:
    bool bfsKarde(vector<int>adj[],vector<int>& color,int node){
        
        color[node]=0;
        queue<int> q;
        q.push(node);
        
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            for(auto i:adj[frontNode])
            {
                if(color[i]==-1 )
                {
                    color[i]=!color[frontNode];
                    q.push(i);
                }
                else if(color[i]==color[frontNode])
                {
                    return true;
                }
            }
        }
        return false;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            bool ans= bfsKarde(adj,color,i);
	            if(ans == true)
	            return false;
	        }
	    }
	    return true;
	}

};
