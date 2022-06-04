class Solution {
public:
    int titleToNumber(string columnTitle) {
         int x;
        int calculation=0;
        int size=columnTitle.size();
        
        for(int i=0;i<size;i++)
        {
            x=columnTitle[i]-64;
            calculation+=(pow(26,size-1-i)*x);
        }
        return calculation;
    }
};