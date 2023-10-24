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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        //ans.push_back(root->val);
        while(!q.empty()){
            int l=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<l;i++){
                TreeNode* node=q.front();
                maxi=max(maxi,node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                q.pop();
            }
            //if(maxi!=INT_MIN){
                ans.push_back(maxi);
            //}
        }
        return ans;
    }
};