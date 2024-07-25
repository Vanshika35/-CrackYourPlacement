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
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == nullptr) return node;
        TreeNode *leftSide = lca(node->left,p,q);
        TreeNode *rightSide = lca(node->right,p,q);
        if((leftSide && rightSide) || (node == p) || (node==q)){
            return node;
        }
        return leftSide == nullptr ? rightSide : leftSide;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};