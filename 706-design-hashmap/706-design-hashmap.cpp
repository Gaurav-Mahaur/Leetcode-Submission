class MyHashMap {
public:
    int mp[1000001];
    MyHashMap() 
    {
        fill(mp,mp+1000001,-1);
        
    }
    
    void put(int key, int value) 
    {
        mp[key] = value;
        
    }
    
    int get(int key) 
    {
        int k = mp[key];
        
        if(k==-1)
        {
            return -1;
        }
        return k;
        
    }
    
    void remove(int key) 
    {
        mp[key] =-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */