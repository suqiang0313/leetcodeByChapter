class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size();
        if(n==-1)
        {
        	return -1;
        }
        int l=0;
        int r=n-1;
        while(l+1<r)
        {
        	int m=l+(r-l)/2;
        	if(matrix[m][0]==target)
        	{
        		return true;
        	}
        	if(matrix[m][0]<target)
        	{
        		l=m;
        	}
        	if(matrix[m][0]>target)
        	{
        		r=m;
        	}
        }
        int row=0;
        if(matrix[r][0]<=target)
        {
        	row=r;
        }
        else
        {
        	row=l;
        }
        l=0;
        r=matrix[0].size()-1;
        while(l+1<r)
        {
        	int m=l+(r-l)/2;
        	if(matrix[row][m]==target)
        	{
        		return true;
        	}
        	if(matrix[row][m]>target)
        	{
        		r=m;
        	}
        	if(matrix[row][m]<target)
        	{
        		l=m;
        	}

        }
        if (matrix[row][l]==target||matrix[row][r]==target)
        {
        	/* code */
        	return true;
        }
        else
        {
        	return false;
        }
    }
};
// another
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