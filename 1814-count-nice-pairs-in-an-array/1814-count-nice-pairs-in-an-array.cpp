class Solution {
public:
    int rev(int n)
    {
	    int revNum = 0;
	    while(n)
        {
            revNum = revNum * 10 + (n % 10), n /= 10;
        }
        return revNum;
    }
    int countNicePairs(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>pref(n);
        vector<int>ans(n);
        unordered_map<int,long long int>mp;
        for(int i=0;i<n;i++)
        {
            pref[i] = rev(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            ans[i] = nums[i]-pref[i];
        }
        for(int i=0;i<n;i++)
        {
            mp[ans[i]]++;
        }
        long long  cnt=0;
        for(auto it:mp)
        {
            cnt = (cnt + (it.second * (it.second - 1)) / 2) % 1000000007; 
        }
        int x = (int)cnt%100000007;
        return cnt;
    }
};