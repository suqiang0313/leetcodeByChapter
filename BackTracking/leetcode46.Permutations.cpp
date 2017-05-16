#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > permute(vector<int>& nums) 
	{
		vector<vector<int> > ret;
		vector<int> temp;
		if(nums.size()==0)
		{
			return ret;
		}
		sort(nums.begin(),nums.end());
		vector<bool> visited(nums.size(),false);
		dfs(ret,temp,nums,visited);
		return ret;
	}
	void dfs(vector<vector<int> > &ret,vector<int> &temp,vector<int> &nums,vector<bool> &visited)
	{
		if(temp.size()==nums.size())
		{
			ret.push_back(temp);
		}
		for (int i=0;i<nums.size();i++)
		{
			if(visited[i]==false)
			{
				temp.push_back(nums[i]);
				visited[i]=true;
				dfs(ret,temp,nums,visited);
				temp.pop_back();
				visited[i]=false;
			}
		}
	}

};
