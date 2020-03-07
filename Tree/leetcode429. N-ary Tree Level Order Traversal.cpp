"""
url:https://leetcode.com/problems/n-ary-tree-level-order-traversal/
description: Given an n-ary tree, 
return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).
"""
// solution : level order :ds:queue
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root ==NULL) {
            return ret;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> each_level;
            for(int i = 0;i<size;i++){
                Node * node = q.front();
                q.pop();
                for(int i = 0;i<node->children.size();i++) {
                    q.push(node->children[i]);
                }
                each_level.push_back(node->val);
            }
            ret.push_back(each_level);
        }
        return ret;
        
    }
};