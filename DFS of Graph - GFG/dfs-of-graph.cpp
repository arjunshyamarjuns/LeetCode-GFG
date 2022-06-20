// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int src, vector<bool>& visited, vector<int> adj[], vector<int>& v)
   {
       visited[src]=true;
       v.push_back(src);
       int node=src;
       for(int i=0;i<adj[node].size();i++)
       {
           if(visited[adj[node][i]]==false)
           {
               dfs(adj[node][i], visited, adj, v);
           }
       }
   }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V);
      vector<int>v;
      v.reserve(V);
       dfs(0, visited, adj, v);
       return v;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends