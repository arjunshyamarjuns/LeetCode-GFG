class Solution {

     map<string,vector<pair<string,double>>> adj;
    map<string,bool> vis;
    
    bool dfs(string& node,string& end,double& pro)
    {
        if(node==end)
            return 1;
        vis[node]=1;
        for(auto& child: adj[node])
        {
            if(vis.count(child.first)) continue;
            pro*=child.second;
            if(dfs(child.first,end,pro))
                return 1;
            pro/=child.second;
        }
        vis[node]=0;
        return 0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        int n = values.size();
        unordered_set<string> s;
        for(int i=0;i<n;i++)
        {
            adj[eq[i][0]].push_back({eq[i][1],values[i]});
            adj[eq[i][1]].push_back({eq[i][0],1/values[i]});
            s.insert(eq[i][0]);
            s.insert(eq[i][1]);
        }
        for(auto& v: queries)
        {
            double pro = 1;
            if(s.count(v[0])==0 or s.count(v[1])==0)
                ans.push_back(-1);
            else{
                bool foundPath = dfs(v[0],v[1],pro);
                if(foundPath)
                    ans.push_back(pro);
                else
                    ans.push_back(-1);
                vis.clear();
            }
        }
        return ans;
    }
};