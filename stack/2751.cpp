class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<vector<int>> ds;
        for(int i = 0; i < n; i++){
            ds.push_back({positions[i], healths[i], directions[i]=='R'?1:0, i});
        }
        
        sort(ds.begin(), ds.end());
        
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            int health1 = ds[i][1];
            int dir1 = ds[i][2];
            
            if(dir1 == 1){
                st.push(i);
            } else {
                while(!st.empty() && health1 > 0){
                    int j = st.top();
                    
                    if(ds[j][1] < health1){
                       
                        st.pop();
                        health1--;
                        ds[j][1] = 0;
                    }
                    else if(ds[j][1] > health1){
                       
                        ds[j][1]--;
                        health1 = 0;
                    }
                    else{
        
                        st.pop();
                        ds[j][1] = 0;
                        health1 = 0;
                    }
                }
                ds[i][1] = health1;
            }
        }
        
        vector<int> result(n, 0);
        
        for(auto &it : ds){
            if(it[1] > 0){
                result[it[3]] = it[1];
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(result[i] > 0) ans.push_back(result[i]);
        }
        
        return ans;
    }
};