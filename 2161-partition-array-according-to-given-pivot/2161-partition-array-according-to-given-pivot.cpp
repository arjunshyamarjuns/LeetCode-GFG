class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      
        int n=nums.size();
          vector<int> sol(n);
        int j=0;

		
        for(int i=0;i<n;i++)
        {
		
            if(nums[i]<pivot){
                sol[j++]=nums[i];
            }
		}
		
        for(int i=0;i<n;i++){
	
            if(nums[i]==pivot){
                sol[j++]=nums[i];
            }
		}

        for(int i=0;i<n;i++)
        {
            if(nums[i]>pivot){
                sol[j++]=nums[i];
            }
		}
        return sol;
        
    }
};