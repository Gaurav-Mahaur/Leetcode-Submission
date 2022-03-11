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
    
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==nullptr)
            return nullptr;
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            n++;
            temp = temp->next;
        }
        if (k%n== 0) {
            return head;
        }
        if(head->next==nullptr)
        {
            return head;
        }
        int d = k%n;
        ListNode* slow = head;
        ListNode* fast = head;
        while(d-- && fast)
        {
            fast = fast->next;
        }
        ListNode* prev = nullptr;
        ListNode* fast_prev=nullptr;
        while(fast)
        {
            prev = slow;
            slow = slow->next;
            fast_prev = fast;
            fast=fast->next;
        }
        prev->next=nullptr;
        fast_prev->next =head;
        
        return slow;
    }
};