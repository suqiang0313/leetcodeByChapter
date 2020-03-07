'''
title :226. Invert Binary Tree
url :https://leetcode.com/problems/invert-binary-tree/
describe: 
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode * left = invertTree(root->right);
        TreeNode * right = invertTree(root->left);
        root->left = left;
        root->right = right;
        return root;
        
    }
};