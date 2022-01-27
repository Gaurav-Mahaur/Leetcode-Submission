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
    ListNode* deleteDuplicates(ListNode* head)
    {
        map<int,int>mp;
        ListNode* curr = head;
        while(curr)
        {
            mp[curr->val]++;
            curr = curr->next;
        }
        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        for(auto it:mp)
        {
            if(it.second==1)
            {
                temp->next = new ListNode(it.first);
                temp =temp->next;
            }
        }
        return newhead->next;
        
        
    }
};