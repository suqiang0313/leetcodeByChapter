class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
    	if(nums.size()==0)
    	{
    		return -1;
    	}
    	int l=0;
    	int r=nums.size()-1;
    	while(l+1<r)
    	{
    		int m=l+(r-l)/2;
    		if(nums[m]==target)
    		{
    			return m;
    		}
    		if(nums[m]>nums[l])
    		{
    			if(nums[m]>=target&&nums[l]<=target)
    			{
    				r=m;
    			}
    			else
    			{
    				l=m;
    			}
    		}
    		else
    		{
    			if(nums[m]<=target&&nums[r]>=target)
    			{
    				l=m;

    			}
    			else
    			{
    				r=m;
    			}
    		}
    	}
    	if(nums[l]==target)
    	{
    		return l;
    	}
    	if(nums[r]==target)
    	{
    		return r;
    	}
    	return -1;
        
    }
};