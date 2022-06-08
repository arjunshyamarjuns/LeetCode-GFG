class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        for(auto i:s)
            mp[i]++;
        string ans ="";
        for(auto i:order)
        {
            if(mp.find(i)!=mp.end())
            {
                while(mp[i]!=0)
                {
                    ans+=i;
                    mp[i]--;
                }
                mp.erase(i);
            }
        }
        for(auto i:mp)
        {
            while(i.second!=0)
            {
                ans+=i.first;
                i.second--;
            }
        }
        return ans;
    }
};