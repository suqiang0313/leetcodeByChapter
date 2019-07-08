'''
url : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
title : 108. Convert Sorted Array to Binary Search Tree
describe: Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
For this problem, 
a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return NULL;
        }
        TreeNode* root = new TreeNode(-1);
        if(n==1) {
            root->val = nums[0];
            return root;
        }
        int mid = n/2;
        root->val = nums[mid];
        vector<int> left(nums.begin(),nums.begin()+mid);
        root->left = sortedArrayToBST(left);
        vector<int> right(nums.begin()+mid+1,nums.end());
        root->right = sortedArrayToBST(right);
        return root;
        
    }
};