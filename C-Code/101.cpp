/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

//BFS
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode *>Tree;
        Tree.push(root);
        while(!Tree.empty())
        {
            int S = Tree.size();
            vector<int>Res;
            for(int i=0 ; i<S ; i++)
            {
                TreeNode * T = Tree.front();
                Tree.pop();
                if(T == NULL)
                    Res.push_back(-1);
                else
                {
                    Tree.push(T->left);
                    Tree.push(T->right);
                    Res.push_back(T->val);
                }
            }
            S = Res.size();
            for(int i=0 ; i<S/2+1 ; i++)
            {
                if(Res[i]!=Res[S-1-i])
                    return false;
            }
        }
        return true;
    }
    
};

//DFS
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
    map<int,vector<int>>Res;
    void DFS(TreeNode * root,int depth)
    {
        if(root == NULL)
        {
            Res[depth].push_back(-1);
            return;
        }
        Res[depth].push_back(root->val);
        DFS(root->left,depth+1);
        DFS(root->right,depth+1);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        DFS(root,1);
        for(auto i = Res.begin() ; i!=Res.end() ; i++)
        {
            vector<int>R = i->second;
            int len = R.size();
            for(int j=0 ; j<len/2+1 ; j++)
            {
                if(R[j] != R[len-1-j])
                    return false;
            }
        }
        return true;
    }
};
