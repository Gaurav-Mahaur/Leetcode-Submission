class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        int n = ops.size();
        vector<int>t;
        //int sum=0;
        //int prev = INT_MIN;
        int size =0;
        for(int i=0;i<n;i++)
        {
            string temp = ops[i];
            if(temp == "C")
            {
                t.pop_back();
                size--;
            }
            else if(temp == "D")
            {
                t.push_back(2*t[size-1]);
                size++;
            }
            else if(temp == "+")
            {
                t.push_back(t[size-1]+t[size-2]);
                size++;
            }
            else
            {
                int num = stoi(temp);
                t.push_back(num);
                size++;
            }
        }
        int sum=0;
        for(int i=0;i<t.size();i++)
        {
            sum += t[i];
        }
        return sum;
    }
};