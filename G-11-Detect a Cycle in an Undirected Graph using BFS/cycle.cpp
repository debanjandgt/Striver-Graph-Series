class Solution {
  public:
    
    bool bfsKarde(int V,vector<int> adj[],vector<int>& visited,map<int,int>& parent,
    int node)
    {
     queue<int> q;
     visited[node]=1;
     parent[node]=-1;
     q.push(node);
     while(!q.empty())
     {
         int frontNode=q.front();
         q.pop();
         for(auto i:adj[frontNode])
         {
             if(visited[i]==0 && i!=parent[frontNode])
             {
                 visited[i]=1;
                 parent[i]=frontNode;
                 q.push(i);
             }
             else if(visited[i]==1 && i!=parent[frontNode])
             {
                 return true;
             }
         }
     }
     return false;
    }
    
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        map<int,int> parent;
        bool ans;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                 ans=bfsKarde(V,adj,visited,parent,i);
                 if(ans)
                 return true;
            }
        }
        return false;
    }
};
