class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
    	vector<int> result;
    	int l=0;
    	int r=numbers.size()-1;
    	while(l+1<r)
    	{
    		if(numbers[l]+numbers[r]==target)
    		{
    			result.push_back(l+1);
    			result.push_back(r+1);
    			return result;
    		}
    		else
    		{
    			if(numbers[l]+numbers[r]>target)
    			{
    				r--;
    			}
    			else
    			{
    				l++;
    			}
    		}

    	}
    	if(numbers[l]+numbers[r]==target)
    	{
    		result.push_back(l+1);
    		result.push_back(r+1);
    	}
    	return result;
        
    }
};