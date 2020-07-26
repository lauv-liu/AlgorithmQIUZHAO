class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>res;
        if(root == NULL){
            return res;
        }
        dfs(res,root);
        return res;
    }
    void dfs(vector<int>&res,Node* root){
        if(root == NULL){
            return;
        }
        res.push_back(root->val);
        for(int i = 0;i<(int) root->children.size();i++){
            dfs(res,root->children[i]);
        }
    }
};