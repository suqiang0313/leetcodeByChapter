"""
url :https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
title : 559. Maximum Depth of N-ary Tree
solution : level order
"""
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
    int maxDepth(Node* root) {
        if(root == NULL){
            return 0;
        }
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            depth = depth + 1;
            for(int i = 0;i < q.size();i++ ){
                Node * p = q.front();
                q.pop();
                for(auto child : p->children){
                    if(child){
                        q.push(child);
                    }
                }
            }
        }
        return depth;
        
    }
};

