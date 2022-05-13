class Solution {
public:
    bool isPalindrome(string s) 
    {
        string curr = "";
        for(int i = 0; i < s.size(); i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                curr += s[i];
            }
        }
        
        transform(curr.begin(),curr.end(), curr.begin(), :: tolower);
        
        int i = 0, j = curr.size() - 1;
        while(i <= j)
        {
            if(curr[i] != curr[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;  
        
        
    }
};