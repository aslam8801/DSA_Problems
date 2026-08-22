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
    int findLeftHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int hgdt = 0;
        while(root){
            hgdt++;
            root = root->left;
        }
        return hgdt;
    }
    int findRightHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int hgdt = 0;
        while(root){
            hgdt++;
            root = root->right;
        }
        return hgdt;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh == rh){
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};