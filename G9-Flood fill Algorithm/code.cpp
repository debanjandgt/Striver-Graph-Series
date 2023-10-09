class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<int> delRow={-1,0,+1,0};
        vector<int> delCol={0,+1,0,-1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        int startingColor=image[sr][sc];
        while(!q.empty())
        {
            auto f=q.front();
            int x=f.first;
            int y=f.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newR=x+delRow[i];
                int newC=y+delCol[i];
                if(newR >= 0 && newR < image.size() && newC >=0 && newC < image[0].size()
                && visited[newR][newC] == 0 && image[newR][newC] == startingColor)
                {
                    visited[newR][newC]=1;
                    image[newR][newC]=newColor;
                    q.push({newR,newC});
                }
            }
        }
        image[sr][sc]=newColor;
        return image;
    }
};
