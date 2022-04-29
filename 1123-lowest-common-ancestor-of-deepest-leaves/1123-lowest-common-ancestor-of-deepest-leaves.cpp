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
    unordered_map<TreeNode*,int>mp;
    int countdepth(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        
            mp[root] = 1+max(countdepth(root->left),countdepth(root->right));
        
        return mp[root];
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        mp[root] = 0;
        countdepth(root);
        int l = mp[root->left];
        int r = mp[root->right];
        TreeNode* p = root;
        while (l != r) {
            if (l > r) {
                p = p->left;
            } else {
                p = p->right;
            }
            l = p->left ? mp[p->left] : 0;
            r = p->right ? mp[p->right] : 0;
        }
        return p;

        
        
    }
};