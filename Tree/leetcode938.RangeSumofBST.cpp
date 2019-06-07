"""
Url:https://leetcode.com/problems/range-sum-of-bst/
Tite: 938. Range Sum of BST
Describe:
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.
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
    int rangeSumBST(TreeNode* root, int L, int R) {
    	if(root == NULL){
    		return 0;
    	}
    	if(root->val >=L && root->val <=R ){
    		return root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
    	}
    	if(root->val <L){
    		return rangeSumBST(root->right,L,R);
    	}
    	return rangeSumBST(root->left,L,R);


    }
};