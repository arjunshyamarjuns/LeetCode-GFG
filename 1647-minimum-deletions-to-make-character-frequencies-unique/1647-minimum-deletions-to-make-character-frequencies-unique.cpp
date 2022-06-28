class Solution {
public:
    int minDeletions(string s) {
      int freq[26]={0};
        for(int i=0;i<s.length();i++)
        {
            freq[s.at(i)-'a']++;
            
        }
        unordered_set<int> occupiedfreq;
        int deletions=0;
        for(int i=0;i<26;i++)
        {
            int currfreq=freq[i];
            while(currfreq>0)
            {
                if(occupiedfreq.find(currfreq)!=occupiedfreq.end())
                    {
                        currfreq--;
                        deletions++;
                    }
                else
                    {
                        break;
                    }
            }
            if(currfreq!=0)
                occupiedfreq.insert(currfreq);
        }
        return deletions;
    }
};