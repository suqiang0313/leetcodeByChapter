"""
url :https://leetcode.com/problems/n-ary-tree-postorder-traversal/
title : 590. N-ary Tree Postorder Traversal
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
	void postorderHelper(Node* root,vector<int>&val){
		if(root == NULL){
			return ;
		}
		for(int i = 0;i<root->children.size();i++){
			postorderHelper(root->children[i],val);
		}
		val.push_back(root->val);
	}
    vector<int> postorder(Node* root) {
    	vector<int> val;
    	postorderHelper(root,val);
    	return val;
        
    }
};
"""
Solution 2: iterative alogrithm
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
    vector<int> postorder(Node* root) {
        stack<Node*> s;
        vector<int> ret;
        if(root == NULL){
            return ret;
        }
        s.push(root);
        while(!s.empty()){
            Node * temp = s.top();
            s.pop();
            for(int i = 0;i<temp->children.size();i++){
                s.push(temp->children[i]);
            }
            ret.push_back(temp->val);
            
        }
        reverse(ret.begin(),ret.end());
        return ret;
        
    }
};
