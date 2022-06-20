class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        deque<int> maxdq;
        deque<int> mindq;
        
        int l = 0;
        int r = 0;
        
        maxdq.push_back(0);
        mindq.push_back(0);

        int ans = 1;
        
        r = 1;
        
        while(r<nums.size()){
            
            while(!maxdq.empty() && nums[maxdq.back()] <= nums[r]){
                maxdq.pop_back();
            }
            maxdq.push_back(r);
            
            while(!mindq.empty() && nums[mindq.back()] >= nums[r]){
                mindq.pop_back();
            }
            mindq.push_back(r);
            
            
            while(nums[maxdq.front()] - nums[mindq.front()] > limit){
                
                if (maxdq.front() == l){
                    maxdq.pop_front();
                }
                if (mindq.front() == l){
                    mindq.pop_front();
                }
                
                l++;
            }
            
            ans = max(ans, r-l+1);
            
            r++;
        }
        
        return ans;
        
    }
};