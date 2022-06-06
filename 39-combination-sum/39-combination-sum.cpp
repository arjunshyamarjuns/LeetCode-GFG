class Solution {
public:
   vector<vector<int>> res;
    void check(vector<int>& cand, int targ, int pos, vector<int>& elem){
        if(targ == 0){
            res.push_back(elem);
            return;
        }
        if(pos == 0)
            return;
        
        if(targ >= cand[pos-1]){
            elem.push_back(cand[pos-1]);
            check(cand, targ - cand[pos-1], pos, elem);
            elem.pop_back();
        }
        check(cand, targ, pos-1, elem);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        check(candidates, target, n, temp);
        return res;
    }
};