class Solution {
public:
       vector<vector<int>> ans;

    void solve(vector<int> &v, int k) {
        if (k == v.size()) {
            ans.push_back(v);
            return;
        }
        
        unordered_set<int> h;
        for (int i=k; i<v.size(); i++) {
            if (h.find(v[i]) == h.end()) {
                h.insert(v[i]);
                swap(v[i], v[k]);
                solve(v, k+1);                
                swap(v[i], v[k]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& v) {
        solve(v, 0);
        return ans;
    }
};