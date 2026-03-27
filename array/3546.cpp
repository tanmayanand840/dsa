class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long>row;
        vector<long long >col;
        long long  sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
            row.push_back(sum);
        }
        sum=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
            }
            col.push_back(sum);
        }
        int p=row.size();
        long long  total=row[p-1];
        for(int i=0;i<p-1;i++){
            long long  curr=row[i];
            long long rem=total-curr;
            if(curr==rem)return true;
        }
        int q=col.size();
        total=col[q-1];
        for(int i=0;i<q-1;i++){
            long long curr=col[i];
            long long rem=total-curr;
            if(curr==rem)return true;
        }
        return false;
    }
};