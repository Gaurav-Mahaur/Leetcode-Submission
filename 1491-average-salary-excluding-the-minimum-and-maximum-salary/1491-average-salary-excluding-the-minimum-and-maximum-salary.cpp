class Solution {
public:
    double average(vector<int>& salary) 
    {
        int n = salary.size();
        sort(salary.begin(),salary.end());
        double s=0;
        for(int i=1;i<n-1;i++)
        {
            s += salary[i];
        }
        double number = n-2;
        
        return s/number;
    }
};