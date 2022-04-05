class Solution {
public:
    string sortednumber(int n)
    {
        string s = to_string(n);
        sort(s.begin(),s.end());
        
        return s;
    }
    bool reorderedPowerOf2(int n) 
    {
        string str = sortednumber(n);
        for(int i=0;i<32;i++)
        {
            if(str == sortednumber(1 << i))
            {
                return true;
            }
        }
        return false;
    }
};