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
    bool getPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* p){
        if(root == nullptr){
            return false;
        }
        path.push_back(root);
        if(root->val == p->val){
            return true;
        }

        if(getPath(root->left, path, p) || getPath(root->right, path, p)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return root;
        }

        vector<TreeNode*> p1;
        vector<TreeNode*> p2;
        getPath(root, p1, p);
        getPath(root, p2, q);

        TreeNode* ans = nullptr;
        int size = min(p1.size(), p2.size());

        for(int i = 0; i < size; i++){
            if(p1[i] == p2[i]){
                ans = p1[i];
            }else{
                break;
            }
        }

        return ans;

    }
};