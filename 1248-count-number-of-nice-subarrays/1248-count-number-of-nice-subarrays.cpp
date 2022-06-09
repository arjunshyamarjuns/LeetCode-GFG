class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int sum=0,ans=0;
     unordered_map<int,int> mp; // Map for storing previous sum value 
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 !=0)
                sum++;
            if(sum==k)
                ans++; // incrementing ans for each sub array with k
            if(mp.count(sum-k))
                ans+=mp[sum-k]; // addding ans to with map value so it will consider all sub array before it.
            mp[sum]++; // add all sum value in map.
        }
        return ans;
    }
};