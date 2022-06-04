class Solution {
public:
    int reverse(int x) {
        long long int rev = 0;
        while(x)
        {
            int last = x%10;
            rev = rev*10 + last;
            x = x/10;
             if(rev <= INT_MIN || rev >= INT_MAX)
             {
                 return 0;
             }
        }
        return rev;
    }
};