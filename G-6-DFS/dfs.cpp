class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfsKarde(ans,visited,adj,i);
            }
        }
        return ans;
    }
    void dfsKarde(vector<int>& ans,vector<int>& visited,vector<int> adj[],int node)
    {
        visited[node]=1;
        ans.push_back(node);
        for(auto i:adj[node])
        {
            if(!visited[i])
             dfsKarde(ans,visited,adj,i);
        }
    }
};  
