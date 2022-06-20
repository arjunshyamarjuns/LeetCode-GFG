// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	     queue<pair<vector<int>,int>> q;
	    q.push({KnightPos,0});
	    vector<pair<int,int>> moves = {{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
	    
	    vector<vector<int>> used(N+1,vector<int>(N+1,INT_MAX));
	    
	    
	    while(q.size()){
	        
	        auto curr = q.front().first;
	        int move = q.front().second;
	        q.pop();
	        
	       // if(curr[0]<=0||curr[1]<=0||curr[0]>N||curr[1]>N||used[curr[0]][curr[1]])
	       //     continue;
	        //used[curr[0]][curr[1]]=true;
	        if(curr==TargetPos)
	            return move;
	        for(auto m : moves){
	            int i=curr[0]+m.first;
	            int j=curr[1]+m.second;
	            if(i>0&&j>0&&i<=N&&j<=N&&used[i][j]>move+1){
	            used[i][j]=move+1;
	            q.push({{i,j},move+1});
	            }
	        }
	        
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends