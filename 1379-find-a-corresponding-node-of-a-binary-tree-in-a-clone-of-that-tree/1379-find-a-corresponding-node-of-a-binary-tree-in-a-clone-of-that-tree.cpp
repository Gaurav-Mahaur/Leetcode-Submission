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
    TreeNode* ans;
    void fun(TreeNode* root1,TreeNode* root2,TreeNode* target)
    {
        if(root1)
        {
            fun(root1->left,root2->left,target);
            if(root1==target)
            {
                ans = root2;
                return;
            }
            fun(root1->right,root2->right,target);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if(original==nullptr)
        {
            return NULL;
        }
        
        fun(original,cloned,target);
        
        return ans;
        
    }
};