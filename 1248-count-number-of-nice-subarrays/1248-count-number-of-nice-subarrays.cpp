class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int sum=0,ans=0;
     unordered_map<int,int> mp; // Map for storing previous sum value 
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 !=0)
                sum++;
            if(sum==k)
                ans++; 
            if(mp.count(sum-k))
                ans+=mp[sum-k]; 
            mp[sum]++;
        }
        return ans;
    }
};