class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int i=0;
        int n=nums.size();
        int sum=0,mx=INT_MIN;
        
        for (i=0; i<n; i++){
          sum+=nums[i];
            mx=max(sum,mx);
            
            if (sum<0)
            {
                sum=0;
            }
        }
        
     return mx;
    }
};