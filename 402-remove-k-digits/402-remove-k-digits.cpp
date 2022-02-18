class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        
        for(auto c : num){                                                //iterating over the whole string
				while(res.length() && res.back()>c && k){  //while k>0 and there's still characters in res and last char is greater than current char
                res.pop_back();
                k--;
            }
            
            if(res.length() || c!='0')        //to ensure that res doesnt have leading 0's
                res.push_back(c);
        }
        
        while(res.length() && k){             //if k is still greater than 0, delete characters from back
            k--;
            res.pop_back();
        }
        
        return res.empty()? "0" : res;         //returning solution
    }
};