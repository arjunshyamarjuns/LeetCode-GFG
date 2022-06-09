class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int n=nums1.size();
        int m=nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0,j=0;
        while(i<n && j<m)
        {
           if(nums1[i] == nums2[j])
           {
                res.push_back(nums1[i]);
                
                while(i < nums1.size()-1 && nums1[i] == nums1[i+1])
                    i++;
                while(j < nums2.size()-1 && nums2[j] == nums2[j+1])
                    j++;
                
                j++;
                i++;
            } 
            else if(nums1[i] < nums2[j]) 
               i++;
              else 
                j++;
                
        }
        return res;
    }
};