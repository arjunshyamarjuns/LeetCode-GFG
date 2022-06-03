class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        vector<int> temp=nums;
        for(int i=0;i<temp.size();i++)
        {
            nums[i]=temp[temp[i]];
        }
        return nums;     
    }
};