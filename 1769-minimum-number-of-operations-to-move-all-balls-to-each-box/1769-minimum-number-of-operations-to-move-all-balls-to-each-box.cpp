class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int>ans;
        map<int,vector<int> > mp;
        for(int i=0;i<n;i++)
        {
            mp[boxes[i]-'0'].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            vector<int> t = mp[1];
            int sum = 0;
            for(int j=0;j<t.size();j++)
            {
                sum += abs(i-t[j]);
            }
            ans.push_back(sum);
        }
        return ans;
         
        
    }
};