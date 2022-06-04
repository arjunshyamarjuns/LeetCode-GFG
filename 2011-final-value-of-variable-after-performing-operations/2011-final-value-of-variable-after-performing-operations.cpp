class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
         int x=0;
        for(string s : operations){
            if(s[0]=='+' or s[2]=='+')
                x++;
            else if(s[0]=='-' or s[2]=='-') 
                x--;
        }
        return x;
    }
};