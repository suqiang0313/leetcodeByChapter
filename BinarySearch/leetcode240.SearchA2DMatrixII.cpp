// solution Binary Search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size()==0||matrix[0].size()==0)
        {
        	return false;
        }
        int M=matrix.size();
        int N=matrix[0].size();
        int i=0;
        int j=N-1;
        while(i<M&&j>=0)
        {
        	if(matrix[i][j]==target)
        	{
        		return true;
        	}
        	if(matrix[i][j]>target)
        	{
        		j--;

        	}
        	if(matrix[i][j]<target)
        	{
        		i++;
        	}
        }
        return false;
        
    }
};