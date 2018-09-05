/*
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example, given a 3-ary tree:

We should return its level order traversal:


[
     [1],
     [3,2,4],
     [5,6]
]
 

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>Res;
        if(root == NULL)
            return Res;
        queue<Node*>Tree;
        Tree.push(root);
        while(!Tree.empty())
        {
            int S = Tree.size();
            vector<int>Temp;
            for(int i=0 ; i<S ; i++)
            {
                Node * node = Tree.front();
                Tree.pop();
                Temp.push_back(node->val);
                int len = node->children.size();
                for(int j=0 ; j<len ; j++)
                {
                    if(node->children[j] != NULL)
                        Tree.push(node->children[j]);
                }
            }
            Res.push_back(Temp);
        }
        return Res;
    }
};
