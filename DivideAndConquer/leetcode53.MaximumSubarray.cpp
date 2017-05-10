//53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
    	int m=INT_MIN;
    	int f=0;
    	for(int i=0;i<nums.size();i++)
    	{
    		f=max(f+nums[i],nums[i]);
    		m=max(f,m);

    	}
    	return m;
        
        
    }
};
// solution 2
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
    	if(nums.size()==0)
    	{
    		return 0;
    	}
    	int l=0;
    	int r=nums.size()-1;
    	return maxSub(nums,l,r);        
    }
    int maxCrossingSum(vector<int>&nums,int l,int m,int h)
    {
    	int sum=0;
    	int left_sum=INT_MIN;
    	for(int i=m;i>=l;i--)
    	{
    		sum=sum+nums[i];
    		if(sum>left_sum)
    		{
    			left_sum=sum;
    		}
    	}
    	int right_sum=INT_MIN;
    	sum=0;
    	for(int i=m+1;i<=h;i++)
    	{
    		sum=sum+nums[i];
    		if(sum>right_sum)
    		{
    			right_sum=sum;
    		}
    	}
    	return left_sum+right_sum;
    }
    int maxSub(vector<int>&nums,int l,int r)
    {
    	if(l==r)
    	{
    		return nums[l];
    	}
    	int m=l+(r-l)/2;
    	int result=max(maxSub(nums,l,m),maxSub(nums,m+1,r));
    	return max(result,maxCrossingSum(nums,l,m,r));
    }
};