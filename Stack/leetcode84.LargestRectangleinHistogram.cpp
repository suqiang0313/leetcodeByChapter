##author:suqiang
##维护一个单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
    	stack<int> S;
    	int maxArea=0;
    	int i=0;
    	while(i<heights.size())
    	{
    		if(S.empty()||S.top()<heights[i])
    		{
    			S.push(heights[i]);
    			i++;
    		}
    		else
    		{
    			int count =0;
    			while(!S.empty()&&S.top()>heights[i])
    			{
    				int top=S.top();
    				S.pop();
    				count++;
    				maxArea=max(maxArea,count*top);
    			}
    			for(int j=0;j<count+1;j++)
    			{
    				S.push(heights[i]);
    			}
    			i++;

    		}

    	}
    	int count=0;
    	while(!S.empty())
    	{
    		count++;
    		maxArea=max(maxArea,count*S.top());
    		S.pop();
    	}
        return maxArea;
    }
};