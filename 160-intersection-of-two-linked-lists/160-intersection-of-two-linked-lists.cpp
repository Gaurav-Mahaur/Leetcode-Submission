/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head)
    {
        if(head==nullptr)
            return 0;
        ListNode* t = head;
        int cnt=0;
        while(t)
        {
            cnt++;
            t = t->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int l1 = length(headA);
        int l2 = length(headB);
        
        ListNode* ptr1;
        ListNode* ptr2;
        if(l1>l2)
        {
            ptr1 = headA;
            ptr2 = headB;
        }
        else
        {
            ptr1 = headB;
            ptr2 = headA;
        }
        int d = abs(l1-l2);
        while(d--)
        {
            ptr1 = ptr1->next;
        }
        
        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1==ptr2)
            {
                return ptr1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return  nullptr;
        
    }
};