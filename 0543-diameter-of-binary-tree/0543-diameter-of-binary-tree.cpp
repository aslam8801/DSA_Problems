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
    int dia(TreeNode* root, int& maxD){
        if(root == nullptr){
            return 0;
        }
        int leftHT = dia(root->left, maxD);
        int rightHT = dia(root->right, maxD);
        maxD = max(maxD, leftHT + rightHT);
        return 1 + max(leftHT, rightHT);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = INT_MIN;
        int ans = dia(root, maxD);
        return maxD;
    }
};