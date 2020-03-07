// problem:709. To Lower Case
// url:https://leetcode.com/problems/to-lower-case/
//solution:将一个字符串转换成小写字母,ascii A-Z: 65-90,a-z:97-122
//method1:

class Solution {
public:
    string toLowerCase(string str) {
        int n = str.size();
        string ret = str;
        for(int i = 0;i < n;i++){
            if(str[i] >= 'A'&&str[i] <= 'Z'){
                ret[i] = ret[i] + 32;
            }
        }
        return ret;
        
    }
};