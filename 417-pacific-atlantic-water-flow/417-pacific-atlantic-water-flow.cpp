class Solution {
public:
   void dfs(int i,int j,vector<vector<int>>& heights,int prev,vector<vector<int>>& ocean){
        int n=heights.size();
        int m=heights[0].size();
        if(i<0 || j<0 || i>=n || j>=m ) 
            return;
        
        if(heights[i][j]<prev || ocean[i][j]) 
            return;   //prev is the neighboring cell and heights[i][j] is curr cell which we are applying dfs
        
        ocean[i][j]=1;
        
        dfs(i+1,j,heights,heights[i][j],ocean);
        dfs(i-1,j,heights,heights[i][j],ocean);
        dfs(i,j-1,heights,heights[i][j],ocean);
        dfs(i,j+1,heights,heights[i][j],ocean);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size()==0 || heights[0].size()==0) return heights;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            dfs(i,0,heights,INT_MIN,pacific);  //we can also pass INT_MIN instead of -1
            dfs(i,m-1,heights,INT_MIN,atlantic);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,heights,INT_MIN,pacific);
            dfs(n-1,j,heights,INT_MIN,atlantic);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back(vector<int>{i,j});
                }
            }
        }
        return ans;
    }
};