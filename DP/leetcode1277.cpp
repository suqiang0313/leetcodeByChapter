"""
leetcode1277:统计全为1的正方形个数
url:https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/
solution:
对于每个元素，统计以该元素为右下角元素的正方形个数
"""

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int ret = 0;
        for(int i =0;i<matrix.size();i++)
        {
            for(int j =0;j<matrix[0].size();j++)
            {
                if(i && j && matrix[i][j])
                {
                    matrix[i][j] = min({matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]}) + 1;
                }
                ret = ret + matrix[i][j];
            }
        }
        return ret;
    }
};
