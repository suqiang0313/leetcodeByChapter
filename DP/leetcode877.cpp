"""
leetcode877:
https://leetcode-cn.com/problems/stone-game/
"""
// min-max method

class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        return score(piles,0,piles.size()-1) > 0;
    }
private:
    int score(const vector<int>& piles, int l, int r)
    {
        if(l == r)
        {
            return piles[l];
        }
        return max(piles[l] - score(piles,l+1,r),
                piles[r] - score(piles,l,r-1));
    }
};


// math method
class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        return true;

    }
};

// dp
class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //dp[i][j]代表从i-j获取的最大的利润
        for(int i =0;i<n;i++)
        {
            dp[i][i] = piles[i];
        }
        for(int dis = 1; dis <n;dis++)
        {
            for(int i =0;i<n-dis;i++)
            {
                dp[i][i+dis] = max(piles[i] -dp[i+1][i+dis],piles[i+dis]-dp[i][i+dis-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};