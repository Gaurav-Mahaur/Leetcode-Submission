class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) 
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>q3;
        q3 = q1;
        q1 = q2;
        q2 = q3;
        
        
    }
    
    int pop() 
    {
        int curr = q1.front();
        q1.pop();
        
        return curr;
    }
    
    int top() 
    {
        int curr = q1.front();
        return curr;
    }
    
    bool empty() 
    {
        if(q1.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */