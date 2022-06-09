class Solution {
public:
  int subarrayCountWithAtMostKchar(vector<int>& arr, int k) 
   {
       int i=0,j=0,count=0;
       unordered_map<int,int> mp;
       while(j<arr.size())
       {
           mp[arr[j]]++;
           if(mp.size()<=k)
           {
               count+=j-i+1;
               j++;
           }
           else 
           {
               while(mp.size()>k)
               {
                   mp[arr[i]]--;
                   if(mp[arr[i]]==0)
                   {
                       mp.erase(arr[i]);
                   }
                   i++;
               }
               if(mp.size()<=k)
               {
                   count+=j-i+1;
               }
               j++;
           }
       }
       return count;
   }
   int subarraysWithKDistinct(vector<int>& nums, int k) 
   {
       int a=subarrayCountWithAtMostKchar(nums,k);
       int b=subarrayCountWithAtMostKchar(nums,k-1);
       return a-b;
   }
};