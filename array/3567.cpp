class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                vector<int> res;
                for(int p=i;p<k+i;p++){
                    for(int q=j;q<k+j;q++){
                        res.push_back(grid[p][q]);
                    }
                }
                sort(res.begin(),res.end());
                if(res.size()==1){
                    ans[i][j]=0;
                    break;
                }
                int mini=INT_MAX;
                for(int i=1;i<res.size();i++){
                    if(res[i]==res[i-1])continue;
                    mini=min(mini,abs(res[i]-res[i-1]));
                }
                ans[i][j]=mini==INT_MAX?0:mini;
            }
        }
        return ans;
    }
};