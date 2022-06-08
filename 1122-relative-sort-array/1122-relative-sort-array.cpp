class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
          vector<int> ans;
        
        sort(arr1.begin(),arr1.end());
        
        int m = arr1.size();
        int n = arr2.size();
        
        //items common in arr2 and arr1 
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(arr2[i]==arr1[j]){
                    ans.push_back(arr1[j]);
                }
            }
        }
        
        
        vector<int> res;
        
        //finding elements of arr1 which is not in arr2
         for(int i=0;i<m;i++){
              int unique = 0;
             
            for(int j=0;j<n;j++){
                if(arr1[i] == arr2[j]){
                    unique = 1;
                }
            }
             
             if(unique==0){
                 res.push_back(arr1[i]);
             }
             
        }
         sort(res.begin(),res.end());
        
        for(int x:res){
            ans.push_back(x);
        }
     
        
        return ans;
        
    
    }
};