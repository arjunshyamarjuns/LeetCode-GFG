class Solution {
public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> ump;
        
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            ump[s].push_back(i);
        }
        
        vector<vector<string>> ans;
        for(auto i : ump){
            vector<string> temp;
            for( auto j : i.second){
                temp.push_back(strs[j]);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};