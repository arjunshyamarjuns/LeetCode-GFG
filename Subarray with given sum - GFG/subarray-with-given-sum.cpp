// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
          int low=0;
       int high=0;
       long long int sum=0;
       vector<int> v;
       
       while(high<=n && low<=n)
       {  
       if(sum==s){
       v.push_back(low+1);
       v.push_back(high);
       return v;
       }
       
       else if(sum<s)
       {
           sum=sum+arr[high++];
       }
       
       if(sum>s)
       {  
          sum=sum-arr[low];
          low++;
       }
       
       }
   v.push_back(-1);
   return v;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends