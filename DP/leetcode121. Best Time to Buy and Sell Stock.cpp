#121. Best Time to Buy and Sell Stock
#url :https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#solution 1 : DP 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int n = prices.size();
        if(n==0){
            return 0;
        }
        vector<int> profit (n,0);
        int min = prices[0];
        for(int i =1;i<n;i++){
            if(prices[i]<min){
                min = prices[i];
            }
            profit[i]=max(prices[i]-min,profit[i-1]);
        }
        return profit[n-1];
        
    }
};

## greedy algorithm

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0) {
            return 0;
        }
        int buy = prices[0];
        int ret = 0;
        for (int i=1;i<n;i++){
            buy = min (buy,prices[i]);
            ret = max (ret,prices[i]-buy);
            
        }
        return ret;
        
        
    }
};