//https://leetcode.com/problems/count-binary-substrings/
//696.Count Binary Substrings
//example:
//Input: "00110011"
//Output: 6
//Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: 
//"0011", "01", "1100", "10", "0011", and "01".
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        groups.push_back(1);
        for(int i = 1;i<s.size();i++){
            if(s[i-1]!=s[i]){
                groups.push_back(1);
            }
            else{
                groups[groups.size()-1] = groups[groups.size()-1] + 1;
            }
        }
        int ret = 0;
        for(int i = 1;i<groups.size();i++){
            ret = ret + min(groups[i-1],groups[i]);
        }
        return ret;
    }
};