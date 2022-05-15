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
    int ans;
   void kthsmallest(TreeNode* &root,int &k)
   {
       if(root==nullptr)
       {
           return;
       }
       
       kthsmallest(root->left,k);
     
       k--;
       if(k==0)
       {
           ans = root->val;
           return ;
       }
       kthsmallest(root->right,k);
   }
    int kthSmallest(TreeNode* root, int k)
    {
      kthsmallest(root,k);
        
        return ans;
        
        
        
    }
};