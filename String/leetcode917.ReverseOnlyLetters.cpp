//url:https://leetcode.com/problems/reverse-only-letters/
//problem:917. Reverse Only Letters
// solution: two pointer
class Solution {
public:
    bool isLetter(char c){
        if(c-'A'>=0 &&c-'Z'<=0){
            return true;
        }
        if(c-'a'>=0 && c-'z'<=0){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string S) {
        string ret = S;
        int begin = 0;
        int end = S.size()-1;
        while(begin < end){
            if(isLetter(ret[begin])&&isLetter(ret[end])){
                char temp = ret[begin];
                ret[begin] = ret[end];
                ret[end] = temp;
                begin ++;
                end--;
            }
            else{
                if(!isLetter(ret[begin])){
                    begin ++;
                }
                if(!isLetter(ret[end])){
                    end--;
                }
            }
        }
        return ret;
    }
};
