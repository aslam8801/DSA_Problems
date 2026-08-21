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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*> q1;
        map<TreeNode*, TreeNode*> mp;
        q1.push(root);
        mp[root] = nullptr;
        while(!q1.empty()){
            TreeNode* f = q1.front();
            q1.pop();
            if(f->left){
                q1.push(f->left);
                mp[f->left] = f;
            }
            if(f->right){
                q1.push(f->right);
                mp[f->right] = f;
            }
        }

        queue<TreeNode*> q2;
        q2.push(target);
        set<TreeNode*> s;
        int dist = 0;
        s.insert(target);
        while(!q2.empty()){
            if(dist == k){
                break;
            }
            int sz = q2.size();
            for(int i = 0; i < sz; i++){
                TreeNode* node = q2.front();
                q2.pop();
                if(node->left && s.find(node->left) == s.end()){
                    q2.push(node->left);
                    s.insert(node->left);
                }
                if(node->right && s.find(node->right) == s.end()){
                    q2.push(node->right);
                    s.insert(node->right);
                }
                if(mp[node] != nullptr && s.find(mp[node]) == s.end()){
                    q2.push(mp[node]);
                    s.insert(mp[node]);
                }
            }
            dist += 1;
        }

        while(!q2.empty()){
            ans.push_back(q2.front()->val);
            q2.pop();
        }
        return ans;
    }
};