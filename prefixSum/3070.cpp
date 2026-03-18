class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>pf(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pf[i][j]+=grid[i][j];
                if(i-1>=0)pf[i][j]+=pf[i-1][j];
                if(j-1>=0)pf[i][j]+=pf[i][j-1];
                if(i-1>=0 && j-1>=0)pf[i][j]-=pf[i-1][j-1];
                if(pf[i][j]<=k)count++;
            }
        }
        return count;
    }
};