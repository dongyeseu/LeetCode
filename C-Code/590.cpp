/*
Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:

Return its postorder traversal as: [5,6,3,2,4,1].

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
    void PostOrderTraversal(Node * root,vector<int>&Res)
    {
        if(root == NULL)
            return;
        int len = root->children.size();
        for(int i=0 ; i<len ; i++)
            PostOrderTraversal(root->children[i],Res);
        Res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>Res;
        PostOrderTraversal(root,Res);
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
    vector<int> postorder(Node* root) {
        vector<int>Res;
        if(root == NULL)
            return Res;
        stack<Node *>Tree;
        Tree.push(root);
        while(!Tree.empty())
        {
            Node * node = Tree.top();
            Tree.pop();
            int len = node->children.size();
            for(int i=0 ; i<len ; i++)
            {
                if(node->children[i]!=NULL)
                    Tree.push(node->children[i]);
            }
            Res.push_back(node->val);
        }
        reverse(Res.begin(),Res.end());
        return Res;
    }
};










