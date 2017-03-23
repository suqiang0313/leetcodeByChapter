class Solution {
public:
    vector<string> readBinaryWatch(int num) 
    {
        vector<string> result;
        for(int i=0;i<12;i++)
        {
        	for(int j=0;j<60;j++)
        	{
        		if(countBinaryOne(i)+countBinaryOne(j)==num)
        		{
        			string s;
        			s.append(to_string(i));
        			if(j<10)
        			{
        				s.append(":0");
        			}
        			else
        			{
        				s.append(":");
        			}
        			s.append(to_string(j));
        			result.push_back(s);
        		}
        	}
        }
        return result;
    }
    int countBinaryOne(int num)
    {
    	int count=0;
    	while(x)
    	{
    		count++;
    		x=x&(x-1);
    	}
    	return count;
    }
};