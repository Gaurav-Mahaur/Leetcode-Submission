class Solution {
public:
    int count=1;
    int findpar(int a,vector<int>&par)
    {
        if(a==par[a])
        {
            return a;
        }
        return par[a] = findpar(par[a],par);
    }
    void unionfind(int a,int b,vector<int>&par,vector<int>&ranks)
    {
        int p = findpar(a,par);
        
        int q = findpar(b,par);
        
        if(p!=q)
        {
            if(ranks[p]<ranks[q])
            {
                par[p] =q;
            }
            else if(ranks[p]>ranks[q])
            {
                par[q]=p;
            }
            else
            {
                par[p]=q;
                ranks[q]++;
            }
        }
        else
        {
            count++;
        }
    }
    int regionsBySlashes(vector<string>& grid) 
    {
        int n =grid.size();
        
        int dots = n+1;
        vector<int>par(dots*dots);
        vector<int>ranks(dots*dots);
        for(int i=0;i<dots*dots;i++)
        {
            par[i] =i;
            ranks[i] =1;
        }
        //int count=1;
        for(int i=0;i<dots;i++)
        {
            for(int j=0;j<dots;j++)
            {
                if(i==0||j==0||i==dots-1||j==dots-1)
                {
                    int cellno = i*dots +j;
                    if(cellno!=0)
                    {
                        unionfind(0,cellno,par,ranks);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '/')
                {
                    int cell1 = (i+1)*dots +j;
                    int cell2 = i*dots +(j+1);
                    
                    unionfind(cell1,cell2,par,ranks);
                }
                else if(grid[i][j]=='\\')
                {
                    int cell1 = i*dots +j;
                    int cell2 = (i+1)*dots + (j+1);
                    
                    unionfind(cell1,cell2,par,ranks);
                }
                        
            }
        }
        return count;
    }
};