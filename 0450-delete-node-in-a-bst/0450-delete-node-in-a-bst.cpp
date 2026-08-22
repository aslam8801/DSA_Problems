class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) {
            return nullptr;
        }

        TreeNode* tar = nullptr;
        TreeNode* curr = root;

        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = nullptr;

        // Find target and store parent
        while(curr) {
            if(curr->val == key) {
                tar = curr;
                break;
            }

            if(key > curr->val) {
                if(curr->right) {
                    mp[curr->right] = curr;
                }
                curr = curr->right;
            } else {
                if(curr->left) {
                    mp[curr->left] = curr;
                }
                curr = curr->left;
            }
        }

        // Key not found
        if(tar == nullptr) {
            return root;
        }

        TreeNode* par = mp[tar];

        TreeNode* left = tar->left;
        TreeNode* right = tar->right;

        // Build replacement subtree
        TreeNode* replacement;

        if(left == nullptr) {
            replacement = right;
        } else {
            replacement = left;

            // Find rightmost node of left subtree
            curr = left;

            while(curr->right) {
                curr = curr->right;
            }

            curr->right = right;
        }

        // Target is root
        if(par == nullptr) {
            return replacement;
        }

        // Connect parent to replacement
        if(par->left == tar) {
            par->left = replacement;
        } else {
            par->right = replacement;
        }

        return root;
    }
};