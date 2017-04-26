//Solution 1 DFS
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        if(nums.size()==0)
        {
            return 0;
        }
        return helper(nums,S,0);
    }
    int helper(vector<int>&nums,int s,int i)
    {
        if(i==nums.size()&&s==0)
        {
            return 1;
        }
        else
        {
            if(i==nums.size())
            {
                return 0;
            }
        }
        return helper(nums,s-nums[i],i+1)+helper(nums,s+nums[i],i+1);
    }
};
