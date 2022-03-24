class MedianFinder {
public:
    priority_queue<int>pqmax;
    priority_queue<int,vector<int>,greater<int> >pqmin;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(pqmax.size()==pqmin.size())
        {
            if(pqmax.size()==0)
            {
                pqmax.push(num);
                return;
            }
            
            if(num<pqmax.top())
            {
                pqmax.push(num);
            }
            else
            {
                pqmin.push(num);
            }
        }
        else
        {
            if(pqmax.size()>pqmin.size())
            {
                if(num>=pqmax.top())
                {
                    pqmin.push(num);
                }
                else
                {
                    int k = pqmax.top();
                    pqmax.pop();
                    pqmin.push(k);
                    pqmax.push(num);
                }
            }
            else
            {
                if(num<=pqmin.top())
                {
                    pqmax.push(num);
                }
                else
                {
                    int k = pqmin.top();
                    pqmin.pop();
                    pqmin.push(num);
                    pqmax.push(k);
                }
            }
            
        }
        
    }
    
    double findMedian() 
    {
        if(pqmax.size()==pqmin.size())
        {
            return (pqmax.top()+pqmin.top())/2.0;
        }
        else if(pqmax.size()>pqmin.size())
        {
            return pqmax.top();
        }
        return pqmin.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */