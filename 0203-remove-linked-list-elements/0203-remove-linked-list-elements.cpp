class Solution {
public:
    ListNode* removeElements(ListNode* head, int val1) {
        while (head != nullptr && head->val == val1) {
            head = head->next;
        }

        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val1) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
