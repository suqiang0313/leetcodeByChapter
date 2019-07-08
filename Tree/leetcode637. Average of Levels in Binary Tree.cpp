'''
url : https://leetcode.com/problems/average-of-levels-in-binary-tree/
'''
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> q;
        if(root == NULL){
            return ret;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double average = 0;
            double sum = 0;
            for(int i = 0;i < size;i++){
                TreeNode * node = q.front();
                q.pop();
                sum = sum + node ->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ret.push_back(sum/size);
        }
        return ret;
    }
};