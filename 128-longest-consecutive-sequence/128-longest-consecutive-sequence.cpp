class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) 
            return 0;
        unordered_map<int,bool>m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]] = true;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            int num=nums[i];
            int temp=num;
            while(m[temp]==true)
            {
                m[temp]=false;
                temp++;
                count++;
            }
        temp=num-1;
        while(m[temp]==true)
        {
            m[temp]=false;
            temp--;
            count++;
        }
        ans=max(ans,count);
    }
    return ans;
    }
};