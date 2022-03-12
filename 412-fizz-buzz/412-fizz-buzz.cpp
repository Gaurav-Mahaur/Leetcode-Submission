class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            string word ="";
            if(i%3==0 && i%5==0)
            {
                word += "FizzBuzz";
            }
            else if(i%5==0)
            {
                word += "Buzz";
            }
            else if(i%3==0)
            {
                word += "Fizz";
            }
            else
            {
                word += to_string(i);
            }
            
            ans.push_back(word);
        }
        return ans;
        
    }
};