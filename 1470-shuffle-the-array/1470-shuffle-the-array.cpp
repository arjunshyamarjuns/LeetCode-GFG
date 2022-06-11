class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>v;
        for(int i=0,j=n;i<n;){
            v.push_back(nums[i]);
            i++;
            v.push_back(nums[j]);
            j++;
        }
        return v;
    }
};