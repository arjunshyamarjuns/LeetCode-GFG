class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0]=1;
        int f2=0,f3=0,f5=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(2*dp[f2],min(3*dp[f3],5*dp[f5]));
            if(dp[i]==2*dp[f2])
                f2++;
            if(dp[i]==3*dp[f3])
                f3++;
            if(dp[i]==5*dp[f5])
                f5++;
        }
        return dp[n-1];
    }
};