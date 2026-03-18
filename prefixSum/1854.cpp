class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mpp;
        int n=logs.size();
        for(int i=0;i<n;i++){
            int birth=logs[i][0];
            int death=logs[i][1];
            mpp[birth]++;
            mpp[death]--;
        }
        int year=0;
        int count=0;
        int maxi=0;
        for(auto it:mpp){
            count+=it.second;
            if(count>maxi){
                year=it.first;
                maxi=count;
            }
        }
        return year;

    }
};