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
    
    ListNode* partition(ListNode* head, int x) 
    {

        ListNode* curr = head;
        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        
        if(curr==nullptr)
        {
            return curr;
        }
        ListNode* other = new ListNode(-3);
        ListNode* another = other;
        while(curr)
        {
            if(curr->val < x)
            {
                temp->next = curr;
                temp=temp->next;
            }
            else
            {
                other->next = new ListNode(curr->val);
                other=other->next;
            }
            curr = curr->next;  
        }
        
        curr = another->next;
        
        while(curr!=nullptr)
        {
            if(curr->val >= x)
            {
                temp->next=curr;
                cout<<curr->val<<" "; 
                temp=temp->next;
            }
            cout<<curr->val<<" ";
            curr=curr->next;
        }
        return newhead->next;
        
    }
};