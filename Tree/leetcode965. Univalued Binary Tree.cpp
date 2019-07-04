"""
url: https://leetcode.com/problems/univalued-binary-tree/
title: 965. Univalued Binary Tree
describe: 判断一棵树中的值是否为唯一值

"""
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
    bool isSame(TreeNode * root,int val){
        if(root == NULL){
            return true;
        }
        if(root->val == val){
            return isSame(root->left,val) && isSame(root->right,val);
        }
        else{
            return false;
        }
    
    }
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int val = root->val;
        return isSame(root,val);
    }
};