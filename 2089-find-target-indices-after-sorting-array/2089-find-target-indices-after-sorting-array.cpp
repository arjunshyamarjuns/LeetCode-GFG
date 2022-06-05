class Solution {
public:
  int bsearch(vector<int> &a, int x){
        int l = 0;
        int r = a.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(a[m] == x) 
                return m;
            else if(a[m] < x)
                l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int index = bsearch(nums,target);
        vector<int> res;
        if(index == -1) return {};
        int i = index-1;
        while(i >= 0){
            if(nums[i] == target) res.push_back(i);
            else break;
            i--;
        }
        res.push_back(index);
        i = index + 1;
        while(i < nums.size()){
            if(nums[i] == target) res.push_back(i);
            else break;
            
            i++;
        }
        sort(res.begin(),res.end());
        return res;
    }
};