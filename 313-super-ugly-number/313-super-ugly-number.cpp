class Solution {
public:
    int nthSuperUglyNumber(int k, vector<int>& primes) {
        int n = primes.size();
        vector<double> dp(k+1,INT_MAX);
        vector<double> counters(n,0);
        dp[0] = 1;
        
        for(int i =1;i<=k;i++){
            for(int j = 0;j<n;j++){
                double x = (double)primes[j];
                dp[i] = min(x*dp[counters[j]], dp[i]);
            }
            for(int j = 0;j<n;j++){
                int x = primes[j];
                if(dp[i]==x*dp[counters[j]]){
                    counters[j]++;
                }
            }
        }
        return (double)dp[k-1];   
    }
};