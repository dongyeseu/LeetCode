/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    bool findTarget(TreeNode* root, int k) {
        vector<int>value;
        if(root == NULL)
            return false;
        queue<TreeNode *>Tree;
        Tree.push(root);
        while(!Tree.empty())
        {
            TreeNode * Node = Tree.front();
            Tree.pop();
            value.push_back(Node->val);
            if(Node->left)
                Tree.push(Node->left);
            if(Node->right)
                Tree.push(Node->right);
        }
        sort(value.begin(),value.end());
        int i = 0, j = value.size()-1;
        while(i < j)
        {
            if(value[i] + value[j] == k)
                return true;
            else if(value[i] + value[j] < k)
                i++;
            else if(value[i] + value[j] > k)
                j--;
        }
        return false;
    }
};
