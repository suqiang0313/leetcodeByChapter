//Solution 516 DP 
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        if(s.size()==0)
        {
            return 0;
        }
        int m=s.size();
        int p[1000][1000];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                p[i][j]=0;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==j)
                {
                    p[j][i]=1;
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        p[j][i]=p[j+1][i-1]+2;
                    }
                    else
                    {
                        p[j][i]=max(p[j+1][i],p[j][i-1]);
                    }
                }
            }
        }
        return p[0][m-1];
        
        
    }
};