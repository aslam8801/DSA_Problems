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
    ListNode* findKthNode(ListNode* curr, int k){
        
        while(curr != nullptr){
            k--;
            if(k == 0){
                break;
            }
            curr = curr->next;
        }

        return curr;
    }
    void reverse(ListNode* head){
        ListNode *prev = nullptr, *curr = head;
        while(curr != nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }

        ListNode *temp = head, *nextNode = temp->next, *prevNode = nullptr;

        while(temp != nullptr){
            ListNode* kthNode = findKthNode(temp, k);

            if(kthNode == nullptr){
                if(prevNode != nullptr){
                    prevNode->next = temp;
                }
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = nullptr;
            
            reverse(temp);
            if(temp == head){
                head = kthNode;
            }else{
                if(prevNode){
                    prevNode->next = kthNode;
                }
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};