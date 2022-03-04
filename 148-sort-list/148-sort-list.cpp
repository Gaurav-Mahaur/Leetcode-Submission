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
    ListNode* mergeList(ListNode* l1 , ListNode* l2)
    {
        ListNode *newhead = new ListNode(0);
        ListNode *curr = newhead;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return newhead->next;
    
    }
    ListNode* sortList(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        
        ListNode* temp = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            temp = slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        
        temp->next = nullptr;
        
        ListNode* l1 = sortList(slow);
        ListNode* l2 = sortList(head);
        
        return mergeList(l1,l2);
        
    }
};