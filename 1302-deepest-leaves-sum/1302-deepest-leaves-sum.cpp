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
    int height(TreeNode* root){
        if(root == NULL)
            return 0; 
        int l=height(root->right);
        int r=height(root->left);
        return 1+max(l,r);
    }
    
   
    
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
       int sum=0;
        int lev =1;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            if(lev++==h)
            {
                break;
            }
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
            }
        }
        while(!q.empty())
        {
            sum += q.front()->val;
            q.pop();
        }
        return sum;
    }
};