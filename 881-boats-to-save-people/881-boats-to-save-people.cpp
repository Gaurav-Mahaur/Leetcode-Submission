class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(people.begin(),people.end());
        int n = people.size();
        int l = 0;
        int r = n-1;
        int cnt=0;
        
        while(l<=r)
        {
            if(people[l]+people[r]<=limit)
            {
                cnt++;
                l++;
                r--;
            }
            else
            {
                cnt++;
                r--;
            }
        }
        return cnt;
    }
};