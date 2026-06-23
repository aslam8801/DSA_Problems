/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        queue<int>oddIdx, evenIdx;
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            cnt++;
            if(cnt % 2 != 0){
                oddIdx.push(curr->val);
            }else{
                evenIdx.push(curr->val);
            }
            curr = curr->next;
        }

        curr = head;
        while(!oddIdx.empty()){
            curr->val = oddIdx.front();
            oddIdx.pop();
            curr = curr->next;
        }

        while(!evenIdx.empty()){
            curr->val = evenIdx.front();
            evenIdx.pop();
            curr = curr->next;
        }

        return head;
    }
};