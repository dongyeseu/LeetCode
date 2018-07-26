/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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
    queue<int>Res1;
    queue<int>Res2;
    void PreOrderTraversel_1(TreeNode * T)
    {
        if(T==NULL)
            return;
        if(T->left==NULL && T->right == NULL)
            Res1.push(T->val);
        PreOrderTraversel_1(T->left);
        PreOrderTraversel_1(T->right);
    }
    void PreOrderTraversel_2(TreeNode * T)
    {
        if(T==NULL)
            return;
        if(T->left==NULL && T->right == NULL)
            Res2.push(T->val);
        PreOrderTraversel_2(T->left);
        PreOrderTraversel_2(T->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        PreOrderTraversel_1(root1);
        PreOrderTraversel_2(root2);
        if(Res1.size() != Res2.size())
            return false;
        else
        {
            while(!Res1.empty() && !Res2.empty())
            {
                if(Res1.front() != Res2.front())
                    return false;
                else
                {
                    Res1.pop();
                    Res2.pop();
                }
            }
            return true;
        }
    }
};
