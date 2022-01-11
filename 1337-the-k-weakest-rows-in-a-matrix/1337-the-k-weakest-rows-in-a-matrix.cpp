class Solution {
public:
    static bool customSort(const pair<int,int> &a,const pair<int,int> &b){
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
       vector<int> result;
        vector< pair <int,int> > v; 
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++){
            int low = 0, high = m-1;
            while(high > low){
                int mid = low + (high-low)/2;
                if(mat[i][mid] > 0){
                    low = mid+1;
                }
                else
                    high = mid;
                    
            }
            if(mat[i][low] != 1)
                low--;
            v.push_back({i,low+1});
        }
        
        sort(v.begin(), v.end(), customSort);
        
        for(int i = 0; i < k; i++){
            result.push_back(v[i].first);
        }
        return result;
    }
};