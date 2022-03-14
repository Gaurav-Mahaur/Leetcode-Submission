/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx=0;
    unordered_map<int,int>mp;
    TreeNode* fun(vector<int>&preorder,vector<int>&inorder,int l,int r)
    {
        if(l>r)
        {
            return nullptr;
        }
        
        int val = preorder[idx++];
        
        TreeNode* root = new TreeNode(val);
        if(l == r)
        {
            return root;
        }
        int mid = mp[val];
        root->left = fun(preorder,inorder,l,mid-1);
        root->right = fun(preorder,inorder,mid+1,r);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int l=0;
        int n=inorder.size();
        int r = preorder.size()-1;
       // unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return fun(preorder,inorder,0,n-1);
        
    }
};