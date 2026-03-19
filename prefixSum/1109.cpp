class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>arr(n,0);
        for(auto it :bookings){
            int first=it[0],second=it[1],seats=it[2];
            arr[first-1]+=seats;
            if(second<n)arr[second]-=seats;
        }
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        return arr;
    }
};