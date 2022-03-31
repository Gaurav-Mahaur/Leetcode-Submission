class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        return p1.second<p2.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        int n = arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        vector<pair<int,int> >temp;
        for(auto it:mp)
        {
            temp.push_back(it);
        }
        sort(temp.begin(),temp.end(),cmp);
        
        int cnt=0;
        int i=0;
        while(k>0 && i<temp.size())
        {
            if(temp[i].second<=k)
            {
                k -= temp[i].second ;
                cnt += 1;
                cout<<cnt<<endl;
            }
            else
            {
                break;
            }
            i++;
        }
        // cout<<mp.size();
        // cout<<cnt;
        int ans = mp.size()-cnt;
        return ans;
    }
};