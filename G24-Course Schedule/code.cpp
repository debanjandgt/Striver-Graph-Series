class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> visited(n,0);
        
        //Make Adj List
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        //Make Indegree
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto j:adj[i])
            {
                inDegree[j]++;
            }
        }
        //Find For 0 indegree nodes
        queue<int> q;

        for(int i=0;i<n;i++)
        {
            if(inDegree[i] == 0)
            q.push(i);
        }
       
       //Reduce the INDEGREE
    vector<int> ans;
       while(!q.empty())
       {
           int frontNode=q.front();
           ans.push_back(frontNode);
           q.pop();
           for(auto i:adj[frontNode])
           {
               inDegree[i]--;
               if(inDegree[i] == 0)
               q.push(i);
           }
       }
       if(ans.size() == n)
       return ans;
       else{
           vector<int> a;
           return a;
       }
    }
};
