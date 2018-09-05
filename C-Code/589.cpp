/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

Return its preorder traversal as: [1,3,5,6,2,4].

Note: Recursive solution is trivial, could you do it iteratively?
*/


//递归
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void PreOrderTraversal(Node * root,vector<int>&Res)
    {
        if(root == NULL)
            return;
        Res.push_back(root->val);
        int len = root->children.size();
        for(int i=0 ; i<len ; i++)
        {
            PreOrderTraversal(root->children[i],Res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>Res;
        PreOrderTraversal(root,Res);
        return Res;
    }
};


//非递归
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>Res;
        if(root == NULL)
            return Res;
        stack<Node *>Tree;
        Tree.push(root);
        while(!Tree.empty())
        {
            Node * node = Tree.top();
            Tree.pop();
            Res.push_back(node->val);
            int len = node->children.size();
            for(int i=len-1 ; i>=0 ; i--)
            {
                if(node->children[i]!=NULL)
                    Tree.push(node->children[i]);
            }
        }
        return Res;
    }
};









