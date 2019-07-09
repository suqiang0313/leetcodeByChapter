"""
url: https://leetcode.com/problems/binary-tree-paths/
title: 257. Binary Tree Paths
describe: 
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

"""
// solution: dfs 
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string ret = "";
        if(root == NULL) {
            return result;
        }
        ret = ret + to_string(root->val);
        dfs(root,result,ret);
        return result;
        
        
        
    }
    void dfs(TreeNode* root,vector<string> &result,string ret) {
        if(root->left == NULL && root->right == NULL) {
            result.push_back(ret);
            return;
        }
        if(root->left!=NULL) {
            dfs(root->left,result,ret+"->"+to_string(root->left->val));
        }
        if(root->right!=NULL) {
            dfs(root->right,result,ret+"->"+to_string(root->right->val));
        }
    }
};