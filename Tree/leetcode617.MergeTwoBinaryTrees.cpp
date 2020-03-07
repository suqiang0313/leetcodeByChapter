"""
url :https://leetcode.com/problems/merge-two-binary-trees/
title : 617. Merge Two Binary Trees
description:
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of new tree.
example:
Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    	if(t1 ==NULL){
    		return t2;
    	}
    	if(t2 ==NULL){
    		return t1;
    	}
    	TreeNode * root = t1;
        root->val = t1->val + t2->val;
    	root->left = mergeTrees(t1->left,t2->left);
    	root->right = mergeTrees(t1->right,t2->right);
    	return root;
        
    }
};

"""
solution 2 :
iterative algorithm
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    	if(t1 == NULL){
    		return t2;
    	}
    	if(t2 == NULL){
    		return t1;
    	}
    	TreeNode * root = t1;
    	stack<TreeNode*>s1,s2;
    	s1.push(t1);
    	s2.push(t2);
    	while(!s1.empty()){
    		TreeNode * c1 = s1.top();
    		TreeNode * c2 = s2.top();
    		s1.pop();
    		s2.pop();
    		c1 ->val = c1 ->val + c2 ->val;
    		if(c1->right == NULL && c2->right !=NULL){
    			c1->right = c2->right;
    		} 
    		else
    			if(c1->right!=NULL && c2->right !=NULL){
    				s1.push(c1->right);
    				s2.push(c2->right);
    			}
    		if(c1->left ==NULL && c2->left !=NULL){
    			c1->left = c2->left;

    		}
    		else
    			if(c1->left!=NULL && c2->left!=NULL){
    				s1.push(c1->left);
    				s2.push(c2->left);
    			}
    	}
    	return root;

        
    }
};