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
    void reorderList(ListNode* head) 
    {
         if ((!head) || (!head->next) || (!head->next->next))
        {
            return;
        }
        stack<ListNode*>st;
        ListNode* curr = head;
        
        int l=0;
        while(curr)
        {
            st.push(curr);
            l++;
            curr=curr->next;
        }
       ListNode* pptr = head;
        for (int j=0; j<l/2; j++) 
        {
            ListNode *element =st.top();
            st.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
        
    }
};