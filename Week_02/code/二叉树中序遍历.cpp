class Solution {
public:
    vector<int>res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return res;
        }
        inTraversal(root);
        return res;
        
    }
    void inTraversal(TreeNode* root){
        if(root == NULL){
            return;
        }
        inTraversal(root->left);
        res.push_back(root->val);
        inTraversal(root->right);
        return;
    }
};