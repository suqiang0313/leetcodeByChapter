//Binary Search
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
    	if(nums.size()==0)
    	{
    		return -1;
    	}
    	int start=0;
    	int end=nums.size()-1;
    	while(start+1<end)
    	{
    		int mid=start+(end-start)/2;
    		if(nums[mid]==nums[end])
    		{
    			end=mid;
    		}
    		if(nums[mid]<nums[end])
    		{
    			end=mid;
    		}
    		else
    		{
    			start=mid;
    		}
    	}
    	return min(nums[start],nums[end]);

        
    }
};