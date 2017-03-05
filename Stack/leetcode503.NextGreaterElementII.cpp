class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
    	if(nums.size()==0)
    	{
    		return nums;
    	}
    	int n=nums.size();
    	vector<int> result(n,-1);
    	stack<int> index;
    	for (int i = 0; i < 2*n; ++i)
    	{
    		/* code */
    		while(!index.empty()&&nums[index.top()]<nums[i%n])
    		{
    			result[index.top]=nums[i%n];
    			index.pop();
    		}
    		if(i<n)
    		{
    			index.push(i);
    		}
    	}
    	return result;
    }        
};