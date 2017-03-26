//leetcode78.Subsets
//Solution1:先求一个空的集合，然后往每一个集合中添加元素
//Example:[1,2,3] 
//step1[]
//step2[][1]
//step3[][1][2][1,2]
//step4[][1][2][1,2][3][1,3][2,3][1,2,3]
//code
class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
        	return result;
        for(vector<int>::iterator ind=nums.begin();ind<nums.end();ind++)
        {
        	int size=result.size();
        	for (int i = 0; i < size; ++i)
        	{
        		std::vector<int> v;
        		for(vector<int>::iterator j=result[i].begin();j<result[i].end();j++)
        		{
                      v.push_back(*j);
        		}
        		v.push_back(*ind);
                result.push_back(v);
        	}
        }
        return result;
    }
};
//Solution2 BackTracking
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int times = 0;
class Solution {
public:
	vector<vector<int> > subsets(vector<int>& nums)
	{
		vector<vector<int> > ret;
		vector<int> sub;

		backtrack(nums, sub, ret, 0);
		return ret;
	}

	void backtrack(vector<int> &nums, vector<int> &sub, vector<vector<int> > &ret, int index)
	{
//		cout <<"times"<< ++times << endl;
		ret.push_back(sub);
		print(ret);
		for (int i = index; i < nums.size(); i++)
		{
			sub.push_back(nums[i]);
			backtrack(nums, sub, ret, i + 1);
			cout << "i==" << i << endl;
			sub.pop_back();
		}
	}
	void print(vector<vector<int>> s)
	{
		cout << "#######################" << endl;
		for (int i = 0; i < s.size();i++)
		{
			if (s[i].empty())
			{
				cout << "empty";
			}
			for (int j = 0; j < s[i].size();j++)
			{
				cout << s[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	vector<int> number;
	number.push_back(1);
	number.push_back(2);
	number.push_back(3);
	Solution S;
	vector<vector<int>> result= S.subsets(number);
}
//Solution3
//BackTracking Solutions 
//is very clear
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return ret;
		}
		dfs(nums, 0);
		return ret;
	}
	void dfs(vector<int> &nums, int pos)
	{
		if (pos == nums.size())
		{
			ret.push_back(temp);
			return;
		}
		temp.push_back(nums[pos]);
		dfs(nums, pos + 1);
		temp.pop_back();
		dfs(nums, pos + 1);
	}
private:
	vector<vector<int>> ret;
	vector<int> temp;
};
//Solution4 bit manipulation
/*
 This is an amazing solution.Learnt a lot.Let me try to explain this to those who didn't get the logic.

 Number of subsets for {1 , 2 , 3 } = 2^3 .
 why ? 
case    possible outcomes for the set of subsets
  1   ->          Take or dont take = 2 
  2   ->          Take or dont take = 2  
  3   ->          Take or dont take = 2 

therefore , total = 2*2*2 = 2^3 = { { } , {1} , {2} , {3} , {1,2} , {1,3} , {2,3} , {1,2,3} }

Lets assign bits to each outcome  -> First bit to 1 , Second bit to 2 and third bit to 3
Take = 1
Dont take = 0
 
0) 0 0 0  -> Dont take 3 , Dont take 2 , Dont take 1 = { } 
1) 0 0 1  -> Dont take 3 , Dont take 2 ,   take 1       =  {1 } 
2) 0 1 0  -> Dont take 3 ,    take 2       , Dont take 1 = { 2 } 
3) 0 1 1  -> Dont take 3 ,    take 2       ,      take 1    = { 1 , 2 } 
4) 1 0 0  ->    take 3      , Dont take 2  , Dont take 1 = { 3 } 
5) 1 0 1  ->    take 3      , Dont take 2  ,     take 1     = { 1 , 3 } 
6) 1 1 0  ->    take 3      ,    take 2       , Dont take 1 = { 2 , 3 } 
7) 1 1 1  ->    take 3     ,      take 2     ,      take 1     = { 1 , 2 , 3 } 

In the above logic ,Insert S[i] only if (j>>i)&1 ==true   { j E { 0,1,2,3,4,5,6,7 }   i = ith element in the input array }

element 1 is inserted only into those places where 1st bit of j is 1 
   if( j >> 0 &1 )  ==> for above above eg. this is true for sl.no.( j )= 1 , 3 , 5 , 7 

element 2 is inserted only into those places where 2nd bit of j is 1 
   if( j >> 1 &1 )  == for above above eg. this is true for sl.no.( j ) = 2 , 3 , 6 , 7

element 3 is inserted only into those places where 3rd bit of j is 1 
   if( j >> 2 & 1 )  == for above above eg. this is true for sl.no.( j ) = 4 , 5 , 6 , 7 

Time complexity : O(n*2^n) , for every input element loop traverses the whole solution set length i.e. 2^n
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};