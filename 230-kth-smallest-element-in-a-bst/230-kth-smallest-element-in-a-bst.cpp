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
    
    void rec(vector<int>&sol , TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        rec(sol,root->left);
        sol.push_back(root->val);
        rec(sol,root->right);
    }
    int kthSmallest(TreeNode* root, int k)
    {
        if(!root)
        {
            return 0;
        }
        vector<int>sol;
        rec(sol,root);
        
        int small = sol[k-1];
        
        return small;
        
    }
};