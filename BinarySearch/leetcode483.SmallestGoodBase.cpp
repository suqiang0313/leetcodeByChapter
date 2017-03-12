class Solution {
public:
    string smallestGoodBase(string n) 
    {
        int64_t num = stoll(n);
        for(int64_t b=2;b<num;b++) 
        {
            int64_t nn = num;
            bool good = 1;
            while(nn) 
            {
                if(nn%b!=1) 
                {
                    good = 0;
                    break;
                }
                nn/=b;
            }
            if(good)
            {
            	return to_string(b);
            }
        }
    }
};