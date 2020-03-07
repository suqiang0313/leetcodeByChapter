##https://leetcode.com/problems/positions-of-large-groups/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ret;
        int n = S.size();
        int i = 0;
        for(int j = 0;j<n;j++){
            if(S[j]!=S[j+1] || j ==n-1){
                if(j-i+1>=3){
                    vector<int> each_ret;
                    each_ret.push_back(i);
                    each_ret.push_back(j);
                    ret.push_back(each_ret);
                   
                }
                i = j+1;
            }
        }
        return ret;
        
    }
};
