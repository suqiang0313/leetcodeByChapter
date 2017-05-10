// solution 1
class Solution {
public:
    string reverseStr(string s, int k) 
    {
        string result=s;
        if(result.size()<k)
        {
            reverse(result.begin(),result.end());
        
        }
        else
        {
            if(result.size()>=2*k)
            {
                reverse(result.begin(),result.begin()+k);
                result=result.substr(0,2*k)+reverseStr(result.substr(2*k),k);
            }
            else
            {
                reverse(result.begin(),result.begin()+k);
            }

        }
        return result;
        
        
    }
};
// Solution 2
class Solution {
public:
    string reverseStr(string s, int k) 
    {
        for(int i=0;i<s.size();i=i+2*k)
        {
            reverse(s.begin()+i,(i+k)>=s.size()?s.end():s.begin()+i+k);
        }
        return s;
        
    }
};