class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> rem;
        
        for(int i = 0; i < rocks.size(); ++i){
            rem.push_back(capacity[i] - rocks[i]);
        }
        
        sort(rem.begin(), rem.end());
        
        int res = 0;
        for(int i = 0; i < rem.size(); i++){
            if(additionalRocks < rem[i])break;
            res++;
            additionalRocks -= rem[i];
        }
        return res;
    }
};