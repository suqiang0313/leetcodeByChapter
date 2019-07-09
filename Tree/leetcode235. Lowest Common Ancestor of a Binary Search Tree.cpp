"""
title: 235. Lowest Common Ancestor of a Binary Search Tree
url :https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

"""
// solution1 : recursive 
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return root;
        }
        if(root->val<=p->val && root->val>=q->val) {
            return root;
        }
        if(root->val>=p->val && root->val<=q->val) {
            return root;
        }
        if(root->val > p->val && root->val >q->val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        return lowestCommonAncestor(root->right,p,q);
        
    }
};
// solution2 : iteration
