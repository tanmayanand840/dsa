/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode* root,string st,vector<string>& ds){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        st+=('a'+root->val);
        reverse(st.begin(),st.end());
        ds.push_back(st);
        return;
    }
    solve(root->left,st+=('a'+root->val),ds);
    st.pop_back();
    solve(root->right,st+=('a'+root->val),ds);

}
    string smallestFromLeaf(TreeNode* root) {
       vector<string>ds;
       string st="";
       solve(root,st,ds);
       sort(ds.begin(),ds.end());
       return ds[0]; 
    }
};