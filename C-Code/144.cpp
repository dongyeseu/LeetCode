/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?


*/


//非递归
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>Res;
        stack<TreeNode *>Tree;
        if(root == NULL)
            return Res;
        Tree.push(root);
        while(!Tree.empty())
        {
            TreeNode * Node = Tree.top();
            Tree.pop();
            Res.push_back(Node->val);
            if(Node->right != NULL)
                Tree.push(Node->right);
            if(Node->left != NULL)
                Tree.push(Node->left);
        }
        return Res;
    }
};
