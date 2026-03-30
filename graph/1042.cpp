class Solution {
public:
    void dfs(int node, vector<int>& vis, unordered_map<int, vector<int>>& adj,
             vector<int>& colors) {
        vis[node-1] = 1;
        for (auto it : adj[node]) {
            if (!vis[it-1]) {
                dfs(it, vis, adj, colors);
            }
        }
        vector<int> choice(4, 0);
        for (auto it : adj[node]) {
            if(colors[it-1]!=0){
            int color = colors[it - 1];
            choice[color - 1] = color;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (choice[i] == 0) {
                colors[node-1] = i + 1;
                break;
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < paths.size(); i++) {
            int u = paths[i][0];
            int v = paths[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        vector<int>color(n,0);
        for (int i = 1; i <= n; i++) {
                if (!vis[i - 1]) {
                    dfs(i, vis, adj, color);
                }
          }
        return color;
    }
};