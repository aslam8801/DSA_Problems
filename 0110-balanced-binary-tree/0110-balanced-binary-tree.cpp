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
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftHT = height(root->left);
        int rightHT = height(root->right);
        return 1 + max(leftHT, rightHT);
    }
    bool isBalance(TreeNode* root){
        if(root == nullptr){
            return true;
        }

        int leftHT = height(root->left);
        int rightHT = height(root->right);

        if(abs(leftHT - rightHT) > 1){
            return false;
        }

        return isBalance(root->left) && isBalance(root->right);
    }
    bool isBalanced(TreeNode* root) {
        return isBalance(root);
    }
};