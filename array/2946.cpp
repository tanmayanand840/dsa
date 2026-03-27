class Solution {
public:
void leftShift(vector<int>& matrix){
    reverse(matrix.begin(),matrix.end());
    reverse(matrix.begin(),matrix.end()-1);
}
void rightShift(vector<int>& matrix){
    reverse(matrix.begin(),matrix.end());
    reverse(matrix.begin()+1,matrix.end());
}
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        vector<vector<int>>matrix=mat;
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                if(j%2==0){
                    leftShift(matrix[j]);
                }else{
                    rightShift(matrix[j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(matrix[i]!=mat[i])return false;
        }
        return true;
        
    }
};