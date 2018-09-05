/*
Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
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
    void InorderTravesel(TreeNode * root,vector<int>&Res)
    {
        if(root == NULL)
            return;
        InorderTravesel(root->left,Res);
        Res.push_back(root->val);
        InorderTravesel(root->right,Res);
    }
    TreeNode * MakeEmpty(TreeNode * root)
    {
        if(root!=NULL)
        {
            MakeEmpty(root->left);
            MakeEmpty(root->right);
            free(root);
        }
        return NULL;
    }
    TreeNode * Insert(TreeNode * root,int x)
    {
        if(root == NULL)
        {
            root = (TreeNode *)malloc(sizeof(TreeNode));
            root->val = x;
            root->left = NULL;
            root->right = NULL;
        }
        else
            root->right = Insert(root->right,x);
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>Res;
        InorderTravesel(root,Res);
        TreeNode * NewRoot = NULL;
        for(auto c:Res)
        {
            NewRoot = Insert(NewRoot,c);
        }
        return NewRoot;
    }
};
