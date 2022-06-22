class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0], col = click[1];
        if(board[row][col] == 'M') board[row][col] = 'X';
        else revealAllPos(board, row, col);
        return board;
    }
    
private:
    int directions[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
    
    void revealAllPos(vector<vector<char>>& board, int row, int col){
       int m = board.size(), n= board[0].size(), mineCount = 0;
	   
        //Check whether mine exists or not in all 8 valid cells
        for(int i=0; i<8; i++){
            int newRow = directions[i][0] + row;
            int newCol = directions[i][1] + col;
            
            if(isValid(newRow, newCol, m, n) && board[newRow][newCol] == 'M') mineCount += 1;
        }
        
        //Reveal adjacent cells if current cell is 'B'
        if(mineCount == 0) {
            board[row][col] = 'B';
            
            for(int i=0; i<8; i++){
                int newRow = directions[i][0] + row;
                int newCol = directions[i][1] + col;

                if(isValid(newRow, newCol, m, n) && board[newRow][newCol] == 'E') {
                    revealAllPos(board, newRow, newCol);
                }
            }
        }
        else board[row][col] = mineCount + 48;
    }
    
    
    bool isValid(int row, int col, int totalRows, int totalCols){
        if(row >= 0 && col >= 0 && row < totalRows && col < totalCols) return true;
        return false;
    }
};