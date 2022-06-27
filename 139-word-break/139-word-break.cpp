class Solution {
public:
    bool f(int i,int n,string s,unordered_map<string,int>&mp,vector<int>&dp)
    {
       if(i>=n)
           return true;
        if(dp[i]!=-1)
            return dp[i];
        string t="";
        for(int k=i;k<n;k++)
        {   
           t+=s[k];
            if(mp.find(t)!=mp.end())
            {
                if(f(k+1,n,s,mp,dp)==true)
                    return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& a) {
        
        int n=s.size();
        unordered_map<string,int>mp;
        for(auto it:a)
            mp[it]++;
        vector<int>dp(n,-1);
       return f(0,n,s,mp,dp); 
    }
};