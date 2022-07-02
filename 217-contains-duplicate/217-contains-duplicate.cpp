class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
         map<int,int>count;
        for(int i=0;i<nums.size();i++)
        {
            if(count[nums[i]]==1)
                return true;
            count[nums[i]]++;
        }
        return false;
    }
};