#https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ret;
        for(int i = 0;i<bits.size();){
            if (bits[i] == 0){
                i = i + 1;
                ret = 1;
            }
            else{
                i = i+2;
                ret = 0;
            }
        }
        return ret;
        
    }
};