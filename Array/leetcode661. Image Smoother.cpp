
#https://leetcode.com/problems/image-smoother/

class Solution {
private: 
    bool valid(int i,int j,vector<vector<int>>& M)
    {
        if (i >=0 && i<M.size() && j>=0 && j<M[0].size())
            return true;
        return false;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> ret(m,vector<int>(n,0));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int sum = 0;
                int num = 0;
                for(int l = -1;l<=1;l++){
                    for(int k = -1;k<=1;k++){
                        if(valid(i+l,j+k,M)){
                            sum = sum + M[i+l][j+k];
                            num = num + 1;
                        }
                    }
                }
                ret[i][j] = sum/num;
            }
        }
        return ret;
    }
};
