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
private:
    vector<int> dfs(TreeNode* node) {
        if(node == nullptr) {
            return {-100000000, 0};
        }
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        return {max({left[0], right[0], left[1] + right[1] + node->val}), max(0, max({0, left[1], right[1]}) + node->val)};
    }
    
public:
    int maxPathSum(TreeNode* root) {
        return dfs(root)[0];
    }
};