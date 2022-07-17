class Solution {
public:
     vector<int> recurse(vector<int>& nums ,int k)
    {
        if(k==nums.size()) return nums;
        nums[k]+=nums[k-1];
        return recurse(nums,k+1);
    }
       
public:
    vector<int> runningSum(vector<int>& nums) {
        
        if(nums.size()==1) return nums;
        return recurse(nums,1);
                
    }
};