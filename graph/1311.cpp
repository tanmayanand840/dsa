class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int k) {
        int n=watchedVideos.size();
        vector<int>vis(n,0);
        vis[id]=1;
        queue<pair<int,int>>q;
        q.push({0,id});
        map<string,int>mpp;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.second;
            int level=it.first;
            if(level==k){
              for(auto itr:watchedVideos[node]){
                mpp[itr]++;
              }
              continue;
            }
            for(auto v:friends[node]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push({level+1,v});
                }
            }

        }
        vector<pair<string,int>> temp;
        for(auto &it : mpp){
            temp.push_back({it.first, it.second});
        }

        sort(temp.begin(), temp.end(), [](auto &a, auto &b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for(auto &it : temp){
            ans.push_back(it.first);
        }

        return ans;

    }
};