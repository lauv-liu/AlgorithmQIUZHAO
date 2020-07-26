class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        if(n <=0 ){
            return NULL;
        }
        vector<int>l_pre;
        vector<int>r_pre;
        vector<int>l_ino;
        vector<int>r_ino;
        int g = preorder[0];
        int i = 0;
        for(;i<m;++i){
            if(inorder[i] == g){
                break;
            }
        }
        TreeNode* root = new TreeNode(inorder[i]);
        for(int j = 0;j<i;j++){
            l_pre.push_back(preorder[j+1]);
            l_ino.push_back(inorder[j]);
        }
        for(int j = i+1;j<n;j++){
            r_pre.push_back(preorder[j]);
            r_ino.push_back(inorder[j]);
        }
        root->left = buildTree(l_pre,l_ino);
        root->right = buildTree(r_pre,r_ino);
        return root;
        
    }
};