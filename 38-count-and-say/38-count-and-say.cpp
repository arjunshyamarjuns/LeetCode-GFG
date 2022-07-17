class Solution {
public:
    string s="1";
    string countAndSay(int n) {
        if(n==1) 
            return s;
        int c=1;
        s+=" ";
        string str="";
        for(int i=0;i<s.length()-1;i++) {
            if(s[i]==s[i+1])
                c++;
            else {
                str+=to_string(c)+s[i];
                c=1;
            }
        }   
        s=str;
        return countAndSay(n-1);
    }
};