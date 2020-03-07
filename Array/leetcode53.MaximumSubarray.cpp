title : leetcode53. Maximum Subarray
url : https://leetcode.com/problems/maximum-subarray/
solution : dp[i] = max(dp[i-1]+nums[i],nums[i])

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        vector<int> ret(n);
        ret [0] = nums[0];
        int max_result = ret[0];
        for(int i = 1;i<n;i++){
            ret[i] = max(ret[i-1],0) + nums[i];
            max_result = max(ret[i],max_result);
        }
        return max_result;
        
    }
};
