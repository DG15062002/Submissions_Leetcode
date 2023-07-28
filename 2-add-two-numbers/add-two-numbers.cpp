class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head, *prev = NULL;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        int carry = 0;
        ListNode* tail = NULL; // Pointer to the end of the result list
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* newNode = new ListNode(sum % 10);
            if (!res) {
                res = newNode;
                tail = newNode; // Update the tail pointer for the first node
            } else {
                tail->next = newNode;
                tail = newNode; // Move the tail pointer to the newly added node
            }
            carry = sum / 10;
        }
        return res;
    }
};
