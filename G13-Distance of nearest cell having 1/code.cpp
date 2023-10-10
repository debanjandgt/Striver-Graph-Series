class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<pair<int, int>, int>> q;
       vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                    grid[i][j]=0;
                }
            }
        }

        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0, 1, 0, -1};


        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;

            q.pop();

            for(int ind=0;ind<delRow.size();ind++){
                int nrow=i+delRow[ind];
                int ncol=j+delCol[ind];

               

    if (nrow >= 0 && nrow < grid.size() && ncol >= 0 
        && ncol < grid[0].size() && grid[nrow][ncol] == 0 && visited[nrow][ncol] == 0)
    {
        grid[nrow][ncol] = t + 1;
        q.push({{nrow, ncol}, t + 1});
        visited[nrow][ncol] = 1;
    }

                }
            
        }

        return grid;


	}
};
