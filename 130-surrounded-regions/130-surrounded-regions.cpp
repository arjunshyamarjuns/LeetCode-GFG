class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<char>>& board)
    {
        if(x<0 ||x>=board.size() ||y<0 || y>=board[0].size() || board[x][y]!='O')
            return ;
        if(vis[x][y]==1)
            return ;
        vis[x][y]=1;
        if(board[x][y]=='O')
        board[x][y]='1';
        dfs(x+1,y,vis,board);
        dfs(x,y+1,vis,board);
        dfs(x-1,y,vis,board);
        dfs(x,y-1,vis,board);
        return ;
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size()));
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i]=='O' && vis[0][i]==0)
            {
                dfs(0,i,vis,board);
            }
            if(board[board.size()-1][i]=='O' && vis[board.size()-1][i]==0)
            {
               dfs(board.size()-1,i,vis,board);
            }
        }
        for(int i=0;i<board.size();i++)
        {
             if(board[i][0]=='O' && vis[i][0]==0)
            {
                dfs(i,0,vis,board);
            }
            if(board[i][board[0].size()-1]=='O' && vis[i][board[0].size()-1]==0)
            {
              dfs(i,board[0].size()-1,vis,board);
            }
        }
      
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='1')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};