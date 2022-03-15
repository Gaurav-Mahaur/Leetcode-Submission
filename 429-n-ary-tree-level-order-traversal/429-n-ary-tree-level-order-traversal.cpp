/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(root==nullptr)
        {
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int>temp;
            temp.clear();
            for(int i=0;i<n;i++)
            {
                Node* t = q.front();
                q.pop();
                
                temp.push_back(t->val);
                
                for(auto it:t->children)
                {
                    if(it!=nullptr)
                    {
                        q.push(it);
                    }
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};