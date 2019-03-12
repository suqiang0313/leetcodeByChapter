##url https://leetcode.com/problems/missing-number/

# 异或操作
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = nums.size();
        for(int i = 0;i<nums.size();i++){
            miss = miss^ i ^ nums[i];
        }
        return miss;
    }
};