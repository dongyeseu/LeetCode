/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    void SumLeft(TreeNode * root,int &sum,int left)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right==NULL && left==1)
            sum += root->val;
        SumLeft(root->left,sum,1);
        SumLeft(root->right,sum,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        SumLeft(root,sum,0);
        return sum;
    }
};




