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
    void diaBT(TreeNode* root, int& maxD){
        if(root == nullptr){
            return ;
        }
        int leftHT = height(root->left);
        int rightHT = height(root->right);
        maxD = max(maxD, leftHT + rightHT);
        diaBT(root->left, maxD);
        diaBT(root->right, maxD);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = INT_MIN;
        diaBT(root, maxD);
        return maxD;
    }
};