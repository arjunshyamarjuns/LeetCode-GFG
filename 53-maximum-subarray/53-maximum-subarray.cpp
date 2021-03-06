class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current=0;
        int max=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            current+=nums[i];
            if(current>max)
                max=current;
            if(current<0)
                current=0;
        }
        return max;
    }
};