class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>> matrix(n,vector<int>(m,0));
       vector<vector<int>>pf(n,vector<int>(m,0));
       int count=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val=0;
            if(grid[i][j]=='X'){
                val=1;
                countX++;
            }else if(grid[i][j]=='Y'){
                val=-1;
            }
            pf[i][j]+=val;
            if(i-1>=0)pf[i][j]+=pf[i-1][j];
            if(j-1>=0)pf[i][j]+=pf[i][j-1];
            if(i-1>=0 && j-1>=0)pf[i][j]-=pf[i-1][j-1];

            matrix[i][j]+=val?1:0;
            if(i-1>=0)matrix[i][j]+=matrix[i-1][j];
            if(j-1>=0)matrix[i][j]+=matrix[i][j-1];
            if(i-1>=0 && j-1>=0)matrix[i][j]-=matrix[i-1][j-1];

            if(pf[i][j]==0 && matrix[i][j]>=1){
                 count++;
            }
        }
       }
       return count;

      
    }
};