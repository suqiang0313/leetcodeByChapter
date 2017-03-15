class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
    	sort(heaters.begin(),heaters.end());
    	int n=heaters.size();
    	int res=0;
    	for(auto i :houses)
    	{
    		int l=0;
    		int r=n-1;
    		while(l<=r)
    		{
    			int m=l+(r-l)/2;
    			if(i<=heaters[m])
    			{
    				r=m-1;
    			}
    			else
    			{
    				l=m+1;
    			}
    		}
    		int t=0;
    		if(l==0)
    		{
    			t=heaters[0]-i;
    		}
    		else
    		{
    			if(l==n)
    			{
    				t=i-heaters[n-1];
    			}
    			else
    			{
    				t=min(i-heaters[l-1],abs(i-heaters[l]));
    			}
    		}
    		res=max(res,t);

    	}
    	return res;
        
    }
};