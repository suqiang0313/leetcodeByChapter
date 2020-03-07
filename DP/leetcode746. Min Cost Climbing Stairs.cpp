## DP
## title :746. Min Cost Climbing Stairs
##url :https://leetcode.com/problems/min-cost-climbing-stairs/
#solution: dp[i] = min(dp[i-1],dp[i-2])+cost[i]
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ret = 0;
        vector<int> dp(n,0);
        dp[0]= cost[0];
        dp[1]= cost[1];
        for(int i =2;i<n;i++){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
};