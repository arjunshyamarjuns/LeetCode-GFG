class Solution {
public:
      void heapAlgo(vector<int>& nums, vector<vector<int>>& res, int k){
        if(k==1){
            res.push_back(nums);
            return;
        }    
        
        for(int i=0; i<k; ++i){
            heapAlgo(nums, res, k-1);
            
            if(k%2==0){
                swap(nums[i], nums[k-1]);
            }else{
                swap(nums[0], nums[k-1]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int k = nums.size();
        
        heapAlgo(nums, res, k);
        return res;
    }
};