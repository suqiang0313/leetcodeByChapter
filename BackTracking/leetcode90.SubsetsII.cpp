class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) 
	{
		vector<vector<int>> ret;
		sort(nums.begin(),nums.end());
		if(nums.size()==0)
		{
			return ret;

		}
		vector<int> temp;
		dfs(ret,temp,nums,0);
		return ret;

	}
	void dfs(vector<vector<int>> &ret,vector<int>&temp,vector<int> nums,int pos)
	{
		ret.push_back(temp);
		for (int i=pos;i<nums.size();i++)
		{
			if(i>pos&&nums[i]==nums[i-1])
			{
				continue;
			}
			temp.push_back(nums[i]);
			dfs(ret,temp,nums,i+1);
			temp.pop_back();

		}


	}
};