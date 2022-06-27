class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        sort(nums.begin(),nums.end());
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        vector<int>v;
        for(int i:s)
        {
            v.push_back(i);
        }
        int mx=1,i=0,j=1;
        while(j<v.size())
        {
            if(v[j]==1+v[j-1])
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else
            {
                i=j;
                j++;
            }
        }
        return mx;
    }
};