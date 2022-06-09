class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int n=s.size();
        int i=0,j=0;
        vector<int>freq(256,0);
        freq[s[0]]++;
        int ans=1;
        while(j<n-1)
        {
            if(freq[s[j+1]]==0)
            {
                j++;
                freq[s[j]]++;
            }
            else
            {
                freq[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};