class Solution {
public:
bool dfsKarde(vector<int>adj[],vector<int>& visited,int node,int& color)
{
    visited[node]=color;
    for(auto i:adj[node])
    {
        if(visited[i]==-1)
        {
            
            color=!visited[node];
            
            bool ans=dfsKarde(adj,visited,i,color);
            if(ans == true)
            return true;
        }
        else if(visited[i] == visited[node])
        {
        return true;
        }
    }
    return false;
}
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> visited(V,-1);
	    int color=0;
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==-1)
	        {
	            bool ans=dfsKarde(adj,visited,i,color);
	            if(ans == true)
	            return false;
	            
	        }
	    }
	    return true;
	}

};
