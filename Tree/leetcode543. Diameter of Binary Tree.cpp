"""
url: https://leetcode.com/problems/diameter-of-binary-tree/
title: 543. Diameter of Binary Tree

descirbe:
Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
"""
//solution
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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        return max(getHeight(root->left)+getHeight(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        
    }
    int getHeight(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(hash.count(root))
        {
            return hash[root];
        }
        hash[root]=max(getHeight(root->left),getHeight(root->right))+1;
        return hash[root];

    }
private:
    unordered_map<TreeNode*,int> hash;
};