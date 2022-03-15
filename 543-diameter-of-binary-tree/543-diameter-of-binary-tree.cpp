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
    int maxdepth(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        return max(maxdepth(root->left),maxdepth(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int maxx = maxdepth(root->left)+maxdepth(root->right);
        //cout<<maxdepth(root->left)<<" "<<maxdepth(root->right)<<endl;
        int k = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
       // cout<<maxx<<endl;
        return max(k,maxx);
        
    }
};