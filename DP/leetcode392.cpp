"""
leetcode392:https://leetcode-cn.com/problems/is-subsequence/
"""
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n == 0 && m == 0)
        {
            return true;
        }
        int index = 0;
        for(int i =0;i<m;i++)
        {
            if(t[i] == s[index])
            {
                index++;
            }
            if(index == n)
            {
                return true;
            }
        }
        return false;

    }
};