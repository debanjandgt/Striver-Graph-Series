class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> visited(N,0);
        
        //Make Adj List
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i].first;
            int v=prerequisites[i].second;
            adj[u].push_back(v);
        }
        //Make Indegree
        vector<int> inDegree(N,0);
        for(int i=0;i<N;i++)
        {
            for(auto j:adj[i])
            {
                inDegree[j]++;
            }
        }
        //Find For 0 indegree nodes
        queue<int> q;

        for(int i=0;i<N;i++)
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
       return ans.size() == N;
	}
};
