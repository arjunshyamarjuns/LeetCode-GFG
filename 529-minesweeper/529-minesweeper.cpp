class Solution {
public:
    int pqr(vector<vector<char>>& board, int x,int y){
        if(x<0||x>=board.size()||y<0||y>=board[0].size()){
            return 0;
        }
        if(board[x][y]=='M'){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    
    
    int xyz(vector<vector<char>>& board, int x,int y){
        return pqr(board,x-1,y-1)+pqr(board,x,y-1)+pqr(board,x-1,y)+pqr(board,x-1,y+1)+pqr(board,x+1,y-1)+pqr(board,x+1,y+1)+pqr(board,x+1,y)+pqr(board,x,y+1);
        
    }
    
    
    
    void abc(vector<vector<char>>& board,int x,int y) {
        if(x<0||x>=board.size()||y<0||y>=board[0].size()){
            return;
            
        }
        if(board[x][y]=='M'){
            board[x][y]='X';
            return;
            
        }
         if(board[x][y]=='X'||board[x][y]=='B'||(board[x][y]>='1'&&board[x][y]<='9')){
            
            return;
            
        }
        if(board[x][y]=='E'){
            if(xyz(board,x,y)>=1){
                board[x][y]='0'+xyz(board,x,y);
            return;
                
            }
            else{
                 board[x][y]='B';
                abc(board,x-1,y-1);
                abc(board,x,y-1);
                abc(board,x-1,y);
                abc(board,x-1,y+1);
                abc(board,x+1,y-1);
                abc(board,x+1,y+1);
                abc(board,x+1,y);
                abc(board,x,y+1);
                return;
                
                
            }
            
        }
    }
        
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        abc(board,click[0],click[1]);
        return board;
      
    }
};