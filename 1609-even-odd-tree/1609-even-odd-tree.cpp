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
    bool isEvenOddTree(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return false;
        }
        queue<TreeNode*>q;
        vector<vector<int> > ans;
        q.push(root);
        int j=0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                v.push_back(t->val);
                
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
            }
            if(j%2==0)
            {
                for(int k=0;k<v.size()-1;k++)
                {
                    if(v[k]%2==0)
                    {
                        return false;
                    }
                    if(v[k]>=v[k+1])
                    {
                        return false;
                    }
                }
                if(v[v.size()-1]%2==0)
                {
                    return false;
                }
            }
            else
            {
                for(int k=0;k<v.size()-1;k++)
                {
                    if(v[k]%2==1)
                    {
                        return false;
                    }
                    if(v[k]<=v[k+1])
                    {
                        return false;
                    }
                }
                if(v[v.size()-1]%2==1)
                {
                    return false;
                }
            }
            j++;
            ans.push_back(v);
        }
        
        return true;
        
    }
};