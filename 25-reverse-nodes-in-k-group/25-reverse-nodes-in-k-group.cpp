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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==nullptr)
        {
            return nullptr;
        }
        int len=0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            len++;
        }
        if(len<k)
        {
            return head;
        }
        int cnt=0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextptr;
        
        while(cnt<k)
        {
            nextptr = curr->next;
            curr->next = prev;
            cnt++;
            
            prev = curr;
            curr = nextptr;
        }
        
        if(nextptr!=nullptr)
        {
            head->next = reverseKGroup(nextptr,k);
        }
        
        return prev;

        
    }
};