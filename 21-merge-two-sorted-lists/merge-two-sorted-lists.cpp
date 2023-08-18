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
    ListNode* newNode(int data)
{
    ListNode* new_node = new ListNode;
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}
 
// Function to insert a new node at the
// end of linked list using recursion.
ListNode* insertEnd(ListNode* head, int data)
{
    // If linked list is empty, create a
    // new node (Assuming newNode() allocates
    // a new node with given data)
    if (head == NULL)
         return newNode(data);
 
    // If we have not reached end, keep traversing
    // recursively.
    else
        head->next = insertEnd(head->next, data);
    return head;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)
            return NULL;
        vector<int> v;
        ListNode* current1=list1;
        ListNode* current2=list2;
        ListNode* head= NULL;
        if(list1!=NULL)
        {
            while(current1)
            {
                v.push_back(current1->val);
                current1=current1->next;
            }
        }
        if(list2!=NULL)
        {
            while(current2)
            {
                v.push_back(current2->val);
                current2=current2->next;
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            head=insertEnd(head,v[i]);
        return head;
    }
};