class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        bool ans;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                parent[i]=-1;
                ans=dfsKarde(adj,visited,parent,i);
                if(ans)
                return true;
            }
        }
        return false;
    }
    bool dfsKarde(vector<int> adj[],unordered_map<int,bool>& visited,
    unordered_map<int,int>& parent,int node)
    {
        for(auto i:adj[node])
        {
            if(!visited[i])
            {
                visited[i]=1;
                parent[i]=node;
                bool ans= dfsKarde(adj,visited,parent,i);
                if(ans)
                return true;
                
            }
            else if(visited[i]==1 && i != parent[node])
            return true;
        }
        return false;
    }
};
