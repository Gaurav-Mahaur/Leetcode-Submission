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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newhead = new ListNode(-1);
        ListNode* t1 = l1;
        ListNode* t2 = l2;
       // int sum=0;
        int carry=0;
        ListNode* temp = newhead;
        while(t1 && t2)
        {
            int sum = t1->val + t2->val + carry;
            
            if(sum>=10)
            {
                sum = sum%10;
                carry =1;
            }
            else
            {
                sum = sum%10;
                carry=0;
            }
            temp->next = new ListNode(sum);
            temp=temp->next;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1)
        {
            int sum = t1->val + carry;
            
            if(sum>=10)
            {
                sum = sum%10;
                carry =1;
            }
            else
            {
                sum = sum%10;
                carry=0;
            }
            temp->next = new ListNode(sum);
            temp=temp->next;
            t1=t1->next;
            //t2=t2->next;
        }
        while(t2)
        {
            int sum =  t2->val + carry;
            
            if(sum>=10)
            {
                sum = sum%10;
                carry =1;
            }
            else
            {
                sum = sum%10;
                carry=0;
            }
            temp->next = new ListNode(sum);
            temp=temp->next;
            //t1=t1->next;
            t2=t2->next;
        }
        if(carry==1)
        {
            temp->next = new ListNode(1);
        }
        
        return newhead->next;
        
    }
};