/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter-1;
    }
    int height(TreeNode* node){
        if(node == nullptr)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        int dia = leftHeight + rightHeight + 1;
        diameter = max(dia, diameter);
        return max(leftHeight, rightHeight)+1;
    }
};