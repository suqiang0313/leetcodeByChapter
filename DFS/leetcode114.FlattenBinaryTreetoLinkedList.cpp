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
    void flatten(TreeNode* root) 
    {
        if(root==NULL)
        {
            return ;
        }
        flatten(root->left);
        flatten(root->right);
        if(root->left==NULL)
        {
            return;
        }
        TreeNode * p=root->left;
        while(p->right)
        {
            p=p->right;
        }
        p->right=root->right;
        root->right=root->left;
        root->left=NULL;
    }

};
// solution 2 use the method of Morris Traversal
//website:http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
class Solution {
public:
    void flatten(TreeNode* root) 
    {
    	while(root)
    	{
    		if(root->left==NULL)
    		{
    			root=root->right;
    		}
    		else
    		{
    			if(root->right)
    			{
    				TreeNode *l=root->left;
    				while(l->right)
    				{
    					l=l->right;
    				}
    				l->right=root->right;

    			}
    			root->right=root->left;
    			root->left==NULL;
    			root=root->right;
    		}
    	}
        
    }
};