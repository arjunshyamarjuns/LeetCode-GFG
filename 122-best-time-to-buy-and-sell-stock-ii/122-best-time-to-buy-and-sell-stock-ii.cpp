class Solution {
public:
      int maxProfit(vector<int>& prices) {
        int m = 0;
        for(int i=prices.size()-2;i>=0;i--)
        {
            if(prices[i]<prices[i+1])
                m += prices[i+1]-prices[i];
        }
        return m;
    }
};