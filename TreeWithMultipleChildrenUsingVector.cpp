/*
// Definition for a Node.
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
*/

class Solution {
public:
    int depth=0;
    void help(Node* root,int level)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->children.size()==0)
        {
            depth=max(depth,level);
        }

        vector<Node*> children = root->children; //when there are more than two children then this is the way of accessing them 
        for(int i=0;i<children.size();i++)
        {
            help(children[i],level+1);
        }
    }
    int maxDepth(Node* root) {
        if(root==NULL)
        {
            return 0;
        }

        help(root,1);

        return depth;
    }
};