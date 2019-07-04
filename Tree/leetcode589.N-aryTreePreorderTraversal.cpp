"""
url :https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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
	void preorderHelper(Node* root,std::vector<int> &v){
		if(root == NULL){
			return;
		}
		v.push_back(root->val);
		for(int i = 0;i<root.children.size();i++){
			preorderHelper(root->children[i],v);
		}
	}
    vector<int> preorder(Node* root) {
    	std::vector<int> ret;
    	preorderHelper(root,ret);
    	return ret;
        
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
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if(root == NULL){
            return ret;
        }
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node * t = s.top();
            s.pop();
            ret.push_back(t->val);
            for(int i = t->children.size()-1;i>=0;i--){
                s.push(t->children[i]);
            }
        }
        return ret;
    }
};