class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int x=pq.top();
            pq.pop();
            pq.push(x+1);
            k--;
        }
        long long  ans=1;
        int mod=1e9+7;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            ans=(1LL*ans*x)%mod;
        }
        return (int)ans;
    }
};