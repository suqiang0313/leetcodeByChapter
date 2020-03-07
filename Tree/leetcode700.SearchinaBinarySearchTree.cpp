"""
url:
https://leetcode.com/problems/search-in-a-binary-search-tree/
description:
700. Search in a Binary Search Tree
"""
// solution1
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!= NULL && root->val != val){
            if(root->val < val){
                root = root ->right;
            }
            else
            {
                root = root ->left;
            }
        }
        return root;
    }
};