/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        vector<int>v;
        ListNode* t = head;
        while(t!=NULL)
        {
            v.push_back(t->val);
            t = t->next;
        }
        sort(v.begin(),v.end());
        ListNode* temp = new ListNode(-1);
        ListNode* newhead = temp;
        for(int i=0;i<v.size();i++)
        {
            int r = v[i];
            temp->next = new ListNode(r);
            temp = temp->next;
        }
        
        return newhead->next;
        
    }
};