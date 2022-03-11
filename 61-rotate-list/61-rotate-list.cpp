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
       
        ListNode* curr=head;

        for (int i=0; i<n-(k%n)-1; ++i) {
            curr = curr->next;
        }
        //prev->next = nullptr;
        ListNode* last = curr;
        
        ListNode* newhead = last->next;
        last->next = nullptr;
        ListNode* t = newhead;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        t->next = head;
        
        return newhead;
        
        
       /*if (head == nullptr) {
            return nullptr;
        }
        ListNode* temp = head;
        int len = 0;
        while (temp) {
            temp = temp->next;
            ++len;
        }
        if (k%len == 0) {
            return head;
        }
        temp = head;
        for (int i=0; i<len-(k%len)-1; ++i) {
            temp = temp->next;
        }
        ListNode* last = temp;
        ListNode* newHead = last->next;
        last->next = nullptr;
        temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        return newHead;*/
    }
};