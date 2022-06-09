class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
           sort(nums.begin(), nums.end());
        if(nums.size()<3)
            return {};
        if(nums[0]>0)     
            return {};
        
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size()-2; i++) {
            if(nums[i]>0) break;
            if(i>0 and nums[i]==nums[i-1]) continue;
            
            int start=i+1, end = nums.size()-1;
            while(start<end) 
            {
                if(nums[start]+nums[end]+nums[i]<0) 
                {
                    start++;
                } 
                else if(nums[start]+nums[end]+nums[i]>0) 
                {
                    end--;
                } 
                else
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    int t1 = nums[start], t2 = nums[end];
                    while(start<end and nums[start]==t1) start++;
                    while(start<end and nums[end]==t2) end--;
                }  
            }   
        }
        
        return ans;
    }
};