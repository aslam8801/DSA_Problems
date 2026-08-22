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
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr){
            return -1;
        }

        priority_queue<int, vector<int>> pq;

        TreeNode* curr = root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            pq.push(f->val);
            while(pq.size() > k){
                pq.pop();
            }
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }

        return pq.top();
    }
};