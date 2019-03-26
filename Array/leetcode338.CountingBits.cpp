//leetcode338:https://leetcode.com/problems/counting-bits/
//338. Counting Bits
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1,0);
        ret[0] = 0;
        if(num<1){
            return ret;
        }
        for(int i =1;i<=num;i++){
            if (i%2==0){
                ret[i] = ret[i/2];
            }
            else{
                ret[i] = ret[i/2]+1;
            }
        }
        return ret;
    }
};
