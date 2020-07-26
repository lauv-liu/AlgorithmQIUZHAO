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
    vector<int>res;
    vector<int> postorder(Node* root) {
        postorderd(root);
        return res;

    }
    void postorderd(Node* root){
        if(root == NULL){
            return;
        }
        for(int i = 0;i<(int)root->children.size();++i){
            postorderd(root->children[i]);
        }
        res.push_back(root->val);
        return;

    }
};