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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr && flag==true){
                    q.push(node->left);
                }else{
                    if(node->left!=nullptr && !flag){
                        return false;
                    }
                    flag=false;
                }
                

                if(node->right!=nullptr && flag==true){
                    q.push(node->right);
                }else{
                    if(node->right!=nullptr && !flag){
                        return false;
                    }
                    flag=false;
                }
            }
        }
        return true;
    }
};