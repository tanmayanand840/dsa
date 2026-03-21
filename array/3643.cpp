class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
      int n=grid.size();
      int m=grid[0].size();
      for(int y1=y;y1<=y+k-1;y1++){
        int i=x;
        int j=x+k-1;
        while(i<j){
            swap(grid[i][y1],grid[j][y1]);
            i++;
            j--;
        }
      }  
      return grid;
    }
};