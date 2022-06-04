class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word3="";
        string word4="";
        for(int i=0;i<word1.size();i++)
        {
           word3=word3+word1[i];
        }
        for(int i=0;i<word2.size();i++)
        {
            word4=word4+word2[i];
        }
        if(word3==word4)
        {
            return true;
        }
        return false;
    }
    
};