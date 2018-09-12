/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>Res;
        if(root == NULL)
            return Res;
        queue<TreeNode *>Tree;
        Tree.push(root);
        while(!Tree.empty())
        {
            int S = Tree.size();
            vector<int>Temp;
            for(int i=0 ; i<S ; i++)
            {
                TreeNode * Node = Tree.front();
                Tree.pop();
                Temp.push_back(Node->val);
                if(Node->left)
                    Tree.push(Node->left);
                if(Node->right)
                    Tree.push(Node->right);
            }
            Res.push_back(Temp);
            Temp.clear();
        }
        reverse(Res.begin(),Res.end());
        return Res;
    }
};





