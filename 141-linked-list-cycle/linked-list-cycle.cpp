/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if (head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // If there is a cycle, slow and fast pointers will meet.
            if (slow == fast) return true;
        }

        // If the fast pointer reaches the end, there is no cycle.
        return false;
    }
};