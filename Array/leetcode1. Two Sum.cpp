'''
Descibe: Given an array of integers, return indices of the two numbers 
such that they add up to a specific target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
demo:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''
// solution: first, Given nums is sorted? you should ask interviewer。
// solution1 : brute force 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int n = nums.size();
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                if(nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};
// using hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> hash;
        for(int i = 0;i<nums.size();i++) {
            hash[nums[i]] = i;
        }
        for(int i = 0;i<nums.size();i++) {
            if(hash[target - nums[i]]!=0 && hash[target-nums[i]] != i) {
                ret.push_back(i);
                ret.push_back(hash[target-nums[i]]);
                break;
            }
        }
        return ret;
        
    }
};