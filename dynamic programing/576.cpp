class Solution {
    int mod=1e9+7;
    int dp[51][51][51];
public:
int solve(int i,int j,int m,int n,int k){
    if((i<0 || j<0 ||i>=m ||j>=n)&& k>=0){
        return 1;
    }
    if(k<=0)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int up=solve(i-1,j,m,n,k-1)%mod;
    int down=solve(i+1,j,m,n,k-1)%mod;
    int left=solve(i,j-1,m,n,k-1)%mod;
    int right=solve(i,j+1,m,n,k-1)%mod;
    return dp[i][j][k]= ((up+down)%mod+(left+right)%mod)%mod;
}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
      return solve(startRow,startColumn,m,n,maxMove);  
    }
};