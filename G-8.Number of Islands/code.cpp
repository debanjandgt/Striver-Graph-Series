class Solution {
  public:
    // Function to find the number of islands.
    vector<int> delRow={-1,0,+1,0};
    vector<int> delCol={0,-1,0,+1};
    queue<pair<int,int>> q;
    void bfsKarde(int i,int j,vector<vector<int>>& visited,vector<vector<char>>& grid)
    {
        q.push({i,j});
        while(!q.empty())
        {
            auto fr=q.front();
            int x=fr.first;
            int y=fr.second;
            q.pop();
            for(int k=0;k<4;k++)
            {
           for(int z=0;z<4;z++)
           {
                int newR=x+delRow[k];
            int newC=y+delCol[z];
            if(newR>=0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() && 
            visited[newR][newC] == 0 && grid[newR][newC] == '1')
            {
                visited[newR][newC]=1;
                q.push({newR,newC});
            }
           }
        }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {
                    bfsKarde(i,j,visited,grid);
                    visited[i][j] =1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
