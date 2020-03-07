"""
title : 404. Sum of Left Leaves
url : https://leetcode.com/problems/sum-of-left-leaves/
describe: 
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0;i<n;i++) {
                TreeNode * node = q.front();
                q.pop();
                if(node->left&&node->left->left==NULL &&node->left->right == NULL) {
                    sum = sum + node->left->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return sum;
    }
};