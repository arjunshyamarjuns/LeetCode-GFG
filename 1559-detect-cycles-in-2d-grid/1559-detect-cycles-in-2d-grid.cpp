class Solution {
public:
 bool isCycle(int i, int j, int lasti, int lastj, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vis[i][j] = 1;
        
        // DLRU
        vector<int> di = {1, 0, 0, -1}, dj = {0, -1, 1, 0};
        for(int dir = 0; dir < 4; dir++) {
            int nexti = i + di[dir];
            int nextj = j + dj[dir];
            
            if(nexti>=0 and nexti<m and nextj>=0 and nextj<n and grid[nexti][nextj]==grid[i][j]) {
                if(vis[nexti][nextj] == 0) {
                    bool isNeighborCycle = isCycle(nexti, nextj, i, j, vis, grid);
                    if(isNeighborCycle) return true;
                } else if(vis[nexti][nextj] == 1 and nexti != lasti and nextj != lastj) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 0) {
                    if(isCycle(i, j, -1, -1, vis, grid) == true) return true;
                }
            }
        }
        
        return false;
    }
};