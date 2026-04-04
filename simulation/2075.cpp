class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=rows;
        int m=encodedText.size()/n;
        vector<vector<char>> matrix(n,vector<char>(m,' '));
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=encodedText[k];
                k++;
                matrix[i][j]=ch;
            }
        }

        string ans="";
        int i=0;
        while(i<m){
            int col=i;
            int j=0;
            while(j<n && col<m){
                ans+=matrix[j][col];
                j++;
                col++;
            }
            i++;
        }
        int q=ans.size()-1;
        for(i=q;i>=0;i--){
            if(ans[i]!=' '){
                q=i;
                break;
            }

        }
        return ans.substr(0,q+1);

    }
};