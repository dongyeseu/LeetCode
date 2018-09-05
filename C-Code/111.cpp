/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode *>Tree;
        Tree.push(root);
        int depth = 0;
        while(!Tree.empty())
        {
            depth++;
            int S = Tree.size();
            for(int i=0 ; i<S ; i++)
            {
                TreeNode * node = Tree.front();
                Tree.pop();
                if(node->left == NULL && node->right==NULL)
                {
                    return depth;
                }
                if(node->left != NULL)
                {
                    Tree.push(node->left);
                }
                if(node->right != NULL)
                {
                    Tree.push(node->right);
                }
            }
        }
    }
};
