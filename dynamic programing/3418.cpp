class Solution {
public:
int dp[501][501][3];
int solve(int i,int j,int n,int m,vector<vector<int>>& coins,int k){
    if(i==n-1 && j==m-1){
        if(coins[i][j]<0 && k>0){
            return 0;
        }
        return coins[i][j];
    }
    if(i>=n || j>=m){
        return INT_MIN;
    }
    if(dp[i][j][k]!=-1e9)return dp[i][j][k];
    int skip=INT_MIN;
    if(coins[i][j]<0 && k>0){
        skip=max(skip,solve(i+1,j,n,m,coins,k-1));
        skip=max(skip,solve(i,j+1,n,m,coins,k-1));
    }
    int next=max(solve(i+1,j,n,m,coins,k),solve(i,j+1,n,m,coins,k));
    int take=INT_MIN;
    if(next!=INT_MIN){
        take=next+coins[i][j];
    }
    return dp[i][j][k]=max(take,skip);
   
    
}
    int maximumAmount(vector<vector<int>>& coins) {
      int n=coins.size();
      int m=coins[0].size();
      for(int i=0;i<=500;i++){
        for(int j=0;j<=500;j++){
            for(int k=0;k<=2;k++){
                dp[i][j][k]=-1e9;
            }
        }
      }
      return solve(0,0,n,m,coins,2);   
    }
};