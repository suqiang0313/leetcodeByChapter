// solution :804. Unique Morse Code Words
//url :https://leetcode.com/problems/unique-morse-code-words/
// title :804. Unique Morse Code Words
//code
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[26] = {".-","-...","-.-.","-..",".","..-."
        ,"--.","....","..",".---","-.-",".-..","--","-.","---",
        ".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
        "-.--","--.."};
        int n = words.size();
        unordered_set<string> ret;
        for(int i = 0; i<n;i++){
            string word = "";
            for(int j = 0;j<words[i].size();j++){
                word = word + code[words[i][j]-'a'];
                
            }
            ret.insert(word);
            
        }
        return ret.size();
    }
};