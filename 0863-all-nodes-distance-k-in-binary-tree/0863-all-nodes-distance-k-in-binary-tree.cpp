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

        queue<TreeNode*> q;
        map<TreeNode*, TreeNode*> mp;
        q.push(root);
        mp[root] = nullptr;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left] = node;
            }

            if(node->right){
                q.push(node->right);
                mp[node->right] = node;
            }
        }

        set<TreeNode*> vis;
        queue<TreeNode*> q2;
        q2.push(target);
        vis.insert(target);
        int dist = 0;

        while(!q2.empty()){
            if(dist == k){
                break;
            }
            int sz = q2.size();
            for(int i = 0; i < sz; i++){
                TreeNode* node = q2.front();
                q2.pop();
                if(node->left && vis.find(node->left) == vis.end()){
                    q2.push(node->left);
                    vis.insert(node->left);
                }

                if(node->right && vis.find(node->right) == vis.end()){
                    q2.push(node->right);
                    vis.insert(node->right);
                }
                if(mp[node] != nullptr && vis.find(mp[node]) == vis.end()){
                    q2.push(mp[node]);
                    vis.insert(mp[node]);
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