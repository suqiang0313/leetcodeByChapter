'''
url: https://leetcode.com/problems/cousins-in-binary-tree/
title: 993. Cousins in Binary Tree
describe: 
In a binary tree, the root node is at depth 0,
and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, 
but have different parents.
We are given the root of a binary tree with unique values, 
and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to 
the values x and y are cousins.
'''
// soultion: level traverse, depth 
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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) {
            return false;
        }
        int depth = 0, depth1 = -1, depth2 = -2;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0;i<size;i++) {
                TreeNode * head = q.front();
                q.pop();
                if(head -> left) {
                    q.push(head->left);
                    if(head->left->val == x) {
                        depth1 = depth;
                    }
                    if(head->left->val == y) {
                        depth2 = depth;
                    }
                }
                if(head ->right) {
                    q.push(head ->right);
                    if(head->right->val == x) {
                        depth1 = depth;
                    }
                    if(head->right->val == y) {
                        depth2 = depth;
                    }
                }
                if(head->left && head->right&&head ->left->val == x && head ->right->val == y) {
                    return false;
                }
                if(head ->left && head->right &&head ->right->val == x && head ->left->val == y) {
                    return false;
                }
            }
            depth++;
            if (depth1 == depth2) {
                return true;
            }

            
        }
        return false;

        
        
    }
};