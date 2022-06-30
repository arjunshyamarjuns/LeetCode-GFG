class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> winner;
        unordered_map<int,int> mp;
        vector<vector<int>>result;
        for(int i=0;i<matches.size();i++)
        {
            winner.insert(matches[i][0]);
            mp[matches[i][1]]++;
        }
        vector<int> one_lost;
        for(auto i:mp)
        {
            if(i.second==1)
                one_lost.push_back(i.first);
            winner.erase(i.first);
        }
        sort(one_lost.begin(),one_lost.end());
        vector<int> not_lost;
        for(auto i:winner)
        {
            if(i)
                not_lost.push_back(i);
        }
        sort(not_lost.begin(),not_lost.end());
        result.push_back(not_lost);
        result.push_back(one_lost);
        return result;
    }
};