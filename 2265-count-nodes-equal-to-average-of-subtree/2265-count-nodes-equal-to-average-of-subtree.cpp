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
    int cnt=0;
    pair<int,int> sumvalue(TreeNode* root)
    {
        if(root==nullptr)
        {
            return {0,0};
        }
        pair<int,int> left = sumvalue(root->left);
        pair<int,int> right = sumvalue(root->right);
        
        int sum = left.first +right.first + root->val;
        int n = left.second + right.second + 1;
        
        cnt += (sum/n==root->val);
        
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) 
    {
        pair<int,int> p1 = sumvalue(root);
        
        return cnt;
        
    }
};