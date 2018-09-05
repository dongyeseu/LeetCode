/*
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example, given a 3-ary tree:

 


 
We should return its max depth, which is 3.

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.
*/

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
    void DFS(int depth,int &maxdepth,Node *root)
    {
        if(root == NULL)
            return;
        if(depth > maxdepth)
        {
            maxdepth = depth;
        }
        for(int i=0 ; i<root->children.size() ; i++)
        {
            Node * nd = root->children[i];
            DFS(depth+1,maxdepth,nd);
        }
        
    }
    int maxDepth(Node* root) {
        int maxdepth = 0;
        DFS(1,maxdepth,root);
        return maxdepth;
    }
};
