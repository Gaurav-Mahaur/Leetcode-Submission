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
    void making_par(TreeNode* &root, unordered_map<TreeNode*,TreeNode*>&par)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            
            if(t->left)
            {
                q.push(t->left);
                par[t->left]=t;
            }
            if(t->right)
            {
                q.push(t->right);
                par[t->right]=t;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,bool>vis;
        unordered_map<TreeNode*,TreeNode*>par;
        
        making_par(root,par);
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int currlevel=0;
        
        while(!q.empty())
        {
            int n = q.size();
            if(currlevel++ == k)
            {
                break;
            }
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->left && vis[t->left]!=true)
                {
                   q.push(t->left);
                    vis[t->left]=true;
                }
                if(t->right && vis[t->right]!=true)
                {
                    q.push(t->right);
                    vis[t->right]=true;
                }
                if(par[t] && vis[par[t]]!=true)
                {
                    q.push(par[t]);
                    vis[par[t]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};