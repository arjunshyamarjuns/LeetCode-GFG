class Solution {
public:
    int climbStairs(int n) {
        int one = 1; 
        int two = 1;
        for(int i =0;i<n-1;i++)
        {
            int k = one+ two;
            two = one;
            one = k;
        }
        return one;
    }
};