class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n = strs.size();
        map<map<char,int>,vector<string>>bigmap;
        for(auto it:strs)
        {
            map<char,int> mp;
            for(int i=0;i<it.size();i++)
            {
                mp[it[i]]++;
            }
            bigmap[mp].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:bigmap)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};