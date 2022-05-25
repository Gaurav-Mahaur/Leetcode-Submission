class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() 
    {
        
        
        
    }
    
    void push(int x) 
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() 
    {
        int x1 = s1.top();
        s1.pop();
        
        return x1;
        
    }
    
    int peek() 
    {
        int k = s1.top();
        
        return k;
        
    }
    
    bool empty() 
    {
        if(s1.empty())
        {
            return true;
        }
        return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */