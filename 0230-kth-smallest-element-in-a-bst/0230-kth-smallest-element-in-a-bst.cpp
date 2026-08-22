class Solution {
public:
    int inorder(TreeNode* root, int& cnt, int k) {
        if(root == nullptr) {
            return -1;
        }

        // Left
        int left = inorder(root->left, cnt, k);

        if(left != -1) {
            return left;
        }

        // Root
        cnt++;

        if(cnt == k) {
            return root->val;
        }

        // Right
        return inorder(root->right, cnt, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inorder(root, cnt, k);
    }
};