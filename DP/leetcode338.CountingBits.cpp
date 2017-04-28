// solution 1 bit 
class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> result;
        for(int i=0;i<=num;i++)
        {
            result.push_back(count(i));
            
        }
        return result;
    }
    int count(int n)
    {
        int count=0;
        while(n)
        {
            ++count;
            n=n&(n-1);
        }
        return count;
    }
};
//solution 2 DP
class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> result(num+1,0);
        for(int i=1;i<=num;i++)
        {
            ans[i]=ans[i/2]+(i%2);
        }
        return result;
    }
};