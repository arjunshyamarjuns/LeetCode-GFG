class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){ que.push({i,j}); vis[i][j]= true;}
            }
        }
        
        auto check = [&](int x, int y){
            if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || grid[x][y]) return false;
            return true;
        };
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        int maxm = 0;
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(int k=0;k<4;k++){
                int DX = dx[k] + x;
                int DY = dy[k] + y;
                if(check(DX,DY)){
                    dist[DX][DY] = dist[x][y] + 1;
                    maxm = max(maxm,dist[DX][DY]);
                    que.push({DX,DY});
                    vis[DX][DY] = true;
                }
            }
        }
        if(maxm==0)
            return -1;
        return maxm;
    }
};