class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int node,unordered_map<int,bool>& visited,
    unordered_map<int,bool>& dfsVisited,vector<int> adj[]){  
        visited[node]=true;
        dfsVisited[node]=true;       
        for(auto neighbour:adj[node])
        {
            if(!(visited[neighbour])){
            bool ans=checkCycle(neighbour,visited,dfsVisited,adj);
            if(ans)
            return true;
            }
            else
            {
                if(dfsVisited[neighbour] == true)
                return true;
            }
        }
        dfsVisited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans=checkCycle(i,visited,dfsVisited,adj);
                if(ans)
                return true;
            }
        }
        return false;
    }
};
