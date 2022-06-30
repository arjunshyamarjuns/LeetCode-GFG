class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int>temp;
        temp=a;
        sort(temp.begin(),temp.end());
        int st=-1;
        int en=-1;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=temp[i]&&st==-1)
            {
                st=i;
              
            }
            else if(a[i]!=temp[i])
            {
                en=i;
            }
        }
       
        if(st==-1)
            return 0;
        return en-st+1;
    }
};