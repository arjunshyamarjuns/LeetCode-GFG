class Solution {
public:
   void recur(vector<vector<char>> &grid,int x,int y,int r,int c){
       if(x<0||x>=r||y<0||y>=c||grid[x][y]!='1')
           return;
       grid[x][y]='2';
       recur(grid,x+1,y,r,c);
       recur(grid,x-1,y,r,c);
       recur(grid,x,y+1,r,c);
       recur(grid,x,y-1,r,c);
   }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int no_of_islands=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    recur(grid,i,j,row,col);
                    no_of_islands++;
                }
            }
        }
        return no_of_islands;
    }
};