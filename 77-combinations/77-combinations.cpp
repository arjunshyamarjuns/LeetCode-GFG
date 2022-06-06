class Solution {
public:
     void solve(int num, int k, int n, vector<int> &subset, vector<vector<int>> &res) {
        if(k == 0) {
            res.push_back(subset);
            return;
        }
        
        for(int i = num; i <= n; i++) {
            subset.push_back(i);
            solve(i + 1, k-1, n, subset, res);
            subset.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        
        solve(1, k, n, subset, res);
        return res;
    }
};