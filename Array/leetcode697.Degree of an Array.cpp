#697. Degree of an Array
#https://leetcode.com/problems/degree-of-an-array/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return n;
        }
        int ret = n;
        int fre = 0;
        
        unordered_map<int,int> leftIndex;
        unordered_map<int,int> counter;
        for(int i = 0;i<n;i++)
        {
            if(leftIndex.count(nums[i]) == 0)
            {
                leftIndex[nums[i]] = i;
            }
            counter[nums[i]] = counter[nums[i]] + 1;
            if(counter[nums[i]] == fre)
            {
                if (i-leftIndex[nums[i]] + 1 <ret)
                {
                    ret = i-leftIndex[nums[i]] + 1;
                }
            }
            if(counter[nums[i]] >fre)
            {
                fre = counter[nums[i]];
                ret = i - leftIndex[nums[i]] + 1;
            }

        }
        return ret;
    }
        
        
};