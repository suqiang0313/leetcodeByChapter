// solution1 
class Solution {
public:
    int climbStairs(int n) 
    {
        return Fib(n,0,1);
        
    }
    int Fib(int n, int ret1, int ret2)
    {
        if(n==1)
        {
            return ret1+ret2;
        }
        return Fib(n-1,ret2,ret1+ret2);
    }
    
};
//solution2
class Solution {
public:
    int climbStairs(int n) 
    {
        int temp0=1;
        int temp1=1;
        int temp2=0;
        if(n<=1)
        {
            return 1;
        }
        for(int i=2;i<=n;i++)
        {
            temp2=temp1+temp0;
            temp0=temp1;
            temp1=temp2;
        }
        return temp2;
        
    }
};
//recursive
