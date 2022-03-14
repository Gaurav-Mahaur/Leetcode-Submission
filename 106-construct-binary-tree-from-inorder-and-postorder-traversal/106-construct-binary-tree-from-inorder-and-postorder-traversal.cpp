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
    unordered_map<int,int>mp;
    int postind;
    TreeNode* fun(vector<int>&inorder ,vector<int>&postorder,int l,int r)
    {
        if(l>r)
        {
            return nullptr;
        }
        int val = postorder[postind];
        postind--;
        TreeNode* root=  new TreeNode(val);
        if(l==r)
        {
            return root;
        }
        int mid = mp[val];
         root->right = fun(inorder,postorder,mid+1,r);
        root->left = fun(inorder,postorder,l,mid-1);
      
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        postind=n-1;
        return fun(inorder,postorder,0,n-1);
    }
};