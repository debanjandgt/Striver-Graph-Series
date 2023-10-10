class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            if(mat[i][0] == 'O')
            q.push({i,0});
            if(mat[i][m-1] == 'O')
            q.push({i,m-1});
        }
        for(int j=0;j<m;j++)
        {
            if(mat[0][j] == 'O')
            q.push({0,j});
            if(mat[n-1][j] == 'O')
            q.push({n-1,j});
        }
        vector<int> delRow={-1,0,+1,0};
        vector<int> delCol={0,+1,0,-1};
        //NOW DO BFS
        while(!q.empty())
        {
            auto fr=q.front();
            int x=fr.first;
            int y=fr.second;
            visited[x][y]=1;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newR=x+delRow[i];
                int newC=y+delCol[i];
                if(newR >= 0 && newR <n && newC >=0 && newC < m && visited[newR][newC] == 0 
                && mat[newR][newC] == 'O')
                {
                    visited[newR][newC]=1;
                    q.push({newR,newC});
                }
            }
        }
        //Final Crush
        vector<vector<char>> ans(n,vector<char>(m,'a'));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j] == 1)
                ans[i][j]='O';
                else
                ans[i][j]='X';
            }
        }
        return ans;
    }
};
