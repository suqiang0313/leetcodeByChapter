'''
url: https://leetcode.com/problems/binary-tree-tilt/
describe : 
Given a binary tree, return the tilt of the whole tree.
The tilt of a tree node is defined as the absolute difference 
between the sum of all left subtree node values and the sum of all right subtree node values.
Null node has tilt 0.
The tilt of the whole tree is defined as the sum of all nodes tilt.
title : 563. Binary Tree Tilt
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
    int postOrder(TreeNode* root, int &sum) {
        if(root==NULL) {
            return 0;
        }
        int left = postOrder(root->left,sum);
        int right = postOrder(root->right,sum);
        sum = sum + abs(right-left);
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        int ret = 0;
        int sum = postOrder(root,ret);
        return ret;
        
    }
};