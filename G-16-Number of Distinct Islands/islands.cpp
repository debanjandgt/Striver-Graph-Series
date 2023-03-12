class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j] == 1)
                {
                    vector<pair<int,int>> vec;
                    dfs(grid,i,j,vec,visited,i,j);
                    s.insert(vec);
                }
            }
        }
        return s.size();
    }
    void dfs(vector<vector<int>>& grid,
    int row,int col,vector<pair<int,int>>& vec,vector<vector<int>>& visited
    ,int row0,int col0){
        
        
         int n=grid.size();
        int m=grid[0].size();
        vec.push_back({row-row0,col-col0});
        visited[row][col]=1;
        int delrow[]={0,+1,0,-1};
        int delcol[]={+1,0,-1,0};
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow >= 0 && nrow < n 
            && ncol >=0 && ncol < m 
            && visited[nrow][ncol]==0 && 
            grid[nrow][ncol] == 1)
            
            {
                dfs(grid,nrow,ncol,vec,visited,row0,col0);
            }
        }
    }
};
