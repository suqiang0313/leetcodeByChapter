//Solution 1
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
    	int l=0;
    	int r=nums.size()-1;
    	while(l+1<r)
    	{
    		int m=l+(r-l)/2;
    		if(nums[m]<target)
    		{
    			l=m;
    		}
    		else
    		{
    			r=m;
    		}
    	}
    	if(nums[l]>=target)
    	{
    		return l;
    	}
    	if(nums[r]>=target)
    	{
    		return r;
    	}
    	return nums.size();
        
    }
};
// Title Search the first time 
[1,2,2,3,4,4] 2
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) 
    {
        // write your code here
        int l=0;
        int r=array.size();
        while(l+1<r)
        {
            int m=l+(r-l)/2;
            if(array[m]==target)
            {
                r=m;
            }
            else
            {
                if(array[m]<target)
                {
                    l=m;
                }
                else
                {
                    r=m;
                    
                }
            }
        }
        if(array[l]==target)
        {
            return l;
        }
        if(array[r]==target)
        {
            return r;
        }
        return-1;
    }
};
