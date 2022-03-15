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
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(root==nullptr)
        {
            return false;
        }
        map<int,pair<int,int>>mp;
        queue<TreeNode*>q;
        q.push(root);
        int lev=0;
        while(!q.empty())
        {
            int n = q.size();
            lev++;
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->left)
                {
                    q.push(t->left);
                    pair<int,int> temp = make_pair(t->val,lev);
                    mp[t->left->val] = temp;;
                }
                if(t->right)
                {
                    q.push(t->right);
                    pair<int,int>temp = make_pair(t->val,lev);
                    mp[t->right->val] = temp;
                }
                    
            }
        }
        
        int par1 = mp[x].first;
        int lev1 = mp[x].second;
        int par2 = mp[y].first;
        int lev2 = mp[y].second;
        
        if(par1!=par2 && lev1==lev2)
        {
            return true;
        }
        return false;
        
    }
};