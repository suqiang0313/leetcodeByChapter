"""
url : https://leetcode.com/problems/leaf-similar-trees/
title : 872. Leaf-Similar Trees

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
    void inOrderTraverse(TreeNode* root,vector<int>&vals){
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            vals.push_back(root->val);
        }
        if(root->left) {
            inOrderTraverse(root->left,vals);
        }
        if(root-> right) {
            inOrderTraverse(root->right,vals);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> val1;
        vector<int> val2;
        inOrderTraverse(root1,val1);
        inOrderTraverse(root2,val2);
        return val1 == val2;
    }
};
