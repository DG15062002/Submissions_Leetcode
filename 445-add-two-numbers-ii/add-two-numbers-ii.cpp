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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current1=l1;
        ListNode* current2=l2;string num1="",num2="";
        ListNode* ans=NULL;
        while(current1)
        {
            num1+=char(48+current1->val);
            current1=current1->next;
        }
        while(current2)
        {
            num2+=char(48+current2->val);
            current2=current2->next;
        }
        string sum="";int carry=0;
        if(num1.length()>num2.length())
        {
            int k=num2.length();
            for(int i=1;i<=num1.length()-k;i++)
            {
                num2="0"+num2;
            }
        }
        else
            if(num2.length()>num1.length())
        {
                int k=num1.length();
            for(int i=1;i<=num2.length()-k;i++)
            {
                num1="0"+num1;
            }
        }
        for(int i=num1.length()-1;i>=0;i--)
        {
            sum=(to_string(((int)(num1[i])+(int)(num2[i])-96+carry)%10))+sum;
            carry=((int)(num1[i])+(int)(num2[i])-96+carry)/10;
        }
        if(carry!=0)
            sum=to_string(carry)+sum;
            while(sum[0]==0&&sum.length()>1)
            sum.erase(sum.begin());
        for(int i=0;i<sum.size();i++)
        ans=insertEnd(ans,(int)(sum[i])-48);
        return ans;
    }
};