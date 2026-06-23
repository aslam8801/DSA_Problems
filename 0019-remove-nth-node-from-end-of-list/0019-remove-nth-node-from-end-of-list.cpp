class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        int noNodes = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            noNodes++;
            curr = curr->next;
        }

        int tar = noNodes - n;

        // delete head
        if (tar == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        curr = head;
        for (int i = 1; i < tar; i++) {
            curr = curr->next;
        }

        ListNode* del = curr->next;
        curr->next = del->next;
        delete del;

        return head;
    }
};