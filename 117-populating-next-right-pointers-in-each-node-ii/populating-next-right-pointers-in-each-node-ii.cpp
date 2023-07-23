/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if (!root) return nullptr;

        Node* dummy = new Node(0); // Dummy node to represent the start of each level
        Node* prev = dummy; // Pointer to the previous node on the current level

        Node* curr = root;
        while (curr) {
            if (curr->left) {
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right) {
                prev->next = curr->right;
                prev = prev->next;
            }
            curr = curr->next;
            if (!curr) {
                curr = dummy->next;
                prev = dummy;
                dummy->next = nullptr; // Clear the next pointer of the dummy node
            }
        }

        delete dummy; // Delete the dummy node
        return root;
    }
};
