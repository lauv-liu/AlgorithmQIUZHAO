class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(isRight(root,p,q)){
            return res;
        }
        return NULL;
        
    }
    bool isRight(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL){
            return false;
        }
        bool r_flage = isRight(root->right,p,q);
        bool l_flage = isRight(root->left,p,q);
        if((r_flage && l_flage) || (root->val == p->val) ||(root->val == q->val)){
            res = root;
        } 
        return r_flage || l_flage || root->val == p->val || root->val == q->val;
    }
};