// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
long long  merge(long long arr[],long long l,long long m,long long r)
{
   long long  inv=0;
   
   long long n=m-l+1,n2=r-m;
   long long a[n],b[n2];
   for(long long i=0;i<n;i++)
   {
       a[i]=arr[i+l];
       
   }
   for(long long i=0;i<n2;i++)
   {
       b[i]=arr[i+m+1];
       
   }
   long long i=0,j=0,k=l;
   while(i<n&&j<n2)
   {
       if(a[i]<=b[j])
       {
           arr[k]=a[i];
           k++,i++;
       }
       else
       {
           arr[k]=b[j];
           inv+=n-i;
           k++,j++;
           
       }
   }
   while(i<n)
   {
       arr[k]=a[i];
       i++,k++;
   }
   while(j<n2)
   {
       arr[k]=b[j];
       j++,k++;
   }
   return inv;
   
   
   
   
}
long long  mergesort(long long arr[],long long l,long long r)
{
   long long  inv=0;
   if(l<r)
   {
       long long mid=(r+l)/2;
       inv+=mergesort(arr,l,mid);
       inv+=mergesort(arr,mid+1,r);
       
       inv+=merge(arr,l,mid,r);
   }
   return inv;
}
long long inversionCount(long long arr[], long long N)
{
   // Your Code Here
   
    return mergesort(arr,0,N-1);
    
}

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends