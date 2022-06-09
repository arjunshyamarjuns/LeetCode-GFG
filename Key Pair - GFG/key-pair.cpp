// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	      int i;
    unordered_map<int,int> mp;
    for(i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(i=0;i<n;i++){
        if(mp.find(x-arr[i]) != mp.end() && x-arr[i] != arr[i]){
            //cout<<arr[i];
            return 1;
        }
        else if(x-arr[1] == arr[i] && mp[arr[i]]>1){
            
            return 1;
        }
    }
    return 0;
}
	
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
  // } Driver Code Ends