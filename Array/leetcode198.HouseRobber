url:https://leetcode.com/problems/house-robber/
title:198. House Robber
solution : dp[i] = max(dp[i-1],dp[i-2]+nums[i])
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int> ret(n,0);
        ret[0] = nums[0];
        ret[1] = max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            ret[i] = max(ret[i-1],ret[i-2]+nums[i]);
        }
        return ret[n-1];
    }
};