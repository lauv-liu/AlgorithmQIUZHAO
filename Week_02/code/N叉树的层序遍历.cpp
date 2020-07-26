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
    vector<vector<int>>res;
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return res;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            queue<Node*>temp = q;
            vector<int>t;
            while(!q.empty()){
                t.push_back(q.front()->val);
                q.pop();
            }
            res.push_back(t);
            while(!temp.empty()){
                Node* n = temp.front();
                for(int i = 0;i<(int)n->children.size();++i){
                    if(n->children[i] != NULL){
                        q.push(n->children[i]);
                    }
                }
                temp.pop();
            }
        }
        return res;
        
    }
};