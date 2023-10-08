class Solution {
public:
    void dfs(int node,unordered_map<int,list<int>>& adj,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it] == 0)
            dfs(it,adj,visited);
        }
    }
    void form(vector<vector<int>>& isConnected,unordered_map<int,list<int>>& adj)
    {
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j] == 1)
                adj[i].push_back(j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,list<int>> adj;
        //form the adjacency LIST;
        form(isConnected,adj);
        int V=isConnected.size();
        vector<int> visited(V,0);
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i] == 0)
            {
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};
