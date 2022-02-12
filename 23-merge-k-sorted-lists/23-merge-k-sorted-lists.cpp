
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return nullptr;
        }
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*> >,greater<pair<int,ListNode*> > > pq;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=nullptr)
            {
                pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        
        while(pq.size())
        {
            pair<int,ListNode*> t = pq.top();
            pq.pop();
            
            temp->next = t.second;
            temp=temp->next;
            
            if(t.second->next!=nullptr)
            {
                pq.push({t.second->next->val,t.second->next});
            }
        }
        
        return newhead->next;
        
    }
};