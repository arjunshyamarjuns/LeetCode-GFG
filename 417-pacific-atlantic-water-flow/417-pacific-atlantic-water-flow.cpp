class Solution {
public:
     void dfs(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>> &ocean)
    {
        if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size())
            return;
        if(ocean[i][j] == 1) return ;
        
        if(matrix[i][j] < prev) return;
        
        ocean[i][j] = 1;
        
        dfs(matrix,i+1,j,matrix[i][j], ocean);
        dfs(matrix,i-1,j,matrix[i][j], ocean);
        dfs(matrix,i,j+1,matrix[i][j], ocean);
        dfs(matrix,i,j-1,matrix[i][j], ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if(matrix.size() < 1) 
            return ans;
        
        vector<vector<int>>pacific(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>atlantic(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int col = 0; col<matrix[0].size(); col++)
        {
            dfs(matrix,0,col,INT_MIN,pacific);
            dfs(matrix,matrix.size()-1,col,INT_MIN,atlantic);
        }
        
        for(int row = 0; row<matrix.size(); row++)
        {
            dfs(matrix,row,0,INT_MIN,pacific);
            dfs(matrix,row,matrix[0].size()-1,INT_MIN,atlantic);
        }
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(pacific[i][j] == 1 and atlantic[i][j] == 1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};
