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
    void sumLeafNodes(TreeNode* root, bool is_left, int& ans){
        if(!root) return;
        if(!root->left && !root->right && is_left){
            ans+= root->val;
        }

        sumLeafNodes(root->left, true, ans);
        sumLeafNodes(root->right, false, ans);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sumLeafNodes(root, false, ans);
        return ans;
    }
};