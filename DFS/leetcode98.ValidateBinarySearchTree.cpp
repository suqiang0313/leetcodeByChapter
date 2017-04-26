/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // solution 1
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
    	if(root==NULL)
    	{
    		return true;
    	}
    	if(root->left==NULL&&root->right==NULL)
    	{
    		return true;
    	}
    	if(root->left==NULL)
    	{
    		return root->val<root->right->val&&root->val<getRightSubtreeLeft(root->right)&&isValidBST(root->right);
    	}
    	if(root->right==NULL)
    	{
    		return root->val>root->left->val&&root->val>getLeftSubtreeRight(root->left)&&isValidBST(root->left);
    	}
    	return  root->val<root->right->val&&root->val<getRightSubtreeLeft(root->right)&&isValidBST(root->right)&&root->val>root->left->val
    	&&root->val>getLeftSubtreeRight(root->left)&&isValidBST(root->left);
        
    }
    int getRightSubtreeLeft(TreeNode * root)
    {
    	if(root->left==NULL)
    	{
    		return root->val;
    	}
    	return getRightSubtreeLeft(root->left);

    }
    int getLeftSubtreeRight(TreeNode * root)
    {
    	if(root->right==NULL)
    	{
    		return root->val;
    	}
    	return getLeftSubtreeRight(root->right);
    }
};
// solution2 区间判断
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
    	return helper(root,LONG_MIN,LONG_MAX);
    }
    bool helper(TreeNode *root,long min,long max)
    {
    	if(root==NULL)
    	{
    		return true;
    	}
    	long  mid=root->val;
    	if(root->val<=min||root->val>=max)
    	{
    		return false;
    	}
    	return helper(root->left,min,mid)&&helper(root->right,mid,max);
    }
};
//Solution3 orderTraverse
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        MiddleTraverse2(root);
        for (int i = 1; i < v.size(); ++i)
        {
        	/* code */
        	if(v[i]<=v[i-1])
        		return false;
        }
        return true;
    }
    void MiddleTraverse(TreeNode * root)
    {
    	if(root==NULL)
    	{
    		return;
    	}
    	MiddleTraverse(root->left);
    	v.push_back(root->val);
    	MiddleTraverse(root->right);
    }
    void MiddleTraverse2(TreeNode *root)
    {
    	if(root==NULL)
    	{
    		return;
    	}
    	TreeNode *p=root;
    	stack<TreeNode*> s;
    	while(p!=NULL||!s.empty())
    	{
    		while(p!=NULL)
    		{
    			s.push(p);
    			p=p->left;
    		}
    		if(!s.empty())
    		{
    			p=s.top();
    			v.push_back(p->val);
    			s.pop();
    			p=p->right;
    		}
    	}
    }
private:
	std::vector<int> v;
};
//Solution 4 DFS
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
    	if(root==NULL)
    	{
    		return true;
    	}
        if(!isValidBST(root->left))
        {
        	return false;

        }
        if(lastNode!=NULL&&lastNode->val>=root->val)
        {
        	return false;
        }
        lastNode=root;
        if(!isValidBST(root->right))
        {
        	return false;
        }
        return true;
    }
private:
	TreeNode * lastNode;
};
//Solution 5 NonRecursive
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
    	long min=LONG_MIN;
    	long max=LONG_MAX;
    	if(root==NULL)
    	{
    		return false;
    	}
    	stack<TreeNode*> S;
    	TreeNode * pre=NULL;
    	while(root!=NULL||!S.empty())
    	{
    		while(root!=NULL)
    		{
    			S.push(root);
    			root=root->left;
    		}
    		root=stack.pop();
    		if(pre!=NULL&&root->val<=pre->val)
    		{
    			return false;
    		}
    		pre=root;
    		root=root->right;
    	}
    	return true;

        
    }
};