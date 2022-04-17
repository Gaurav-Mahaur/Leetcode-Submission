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
    void inorder(TreeNode* root,vector<int>&sol)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left,sol);
        sol.push_back(root->val);
        inorder(root->right,sol);
    }
    TreeNode* increasingBST(TreeNode* root)
    {
        vector<int> sol;
        inorder(root,sol);
        
        TreeNode * newnode = new TreeNode(0);
        TreeNode* curr = newnode;
        for(int i=0;i<sol.size();i++)
        {
            curr->right = new TreeNode(sol[i]);
            curr = curr->right;
        }
        
        return newnode->right;
    }
};