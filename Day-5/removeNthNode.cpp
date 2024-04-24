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


//Brute Force sol
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        int cnt = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        if (cnt == n) {
            ListNode* newhead = head->next;
            delete (head);
            return newhead;
        }
        int res = cnt - n-1;
        temp = head;
        int i=0;
        while(i<res)
        {
            temp=temp->next;
            i++;
        }
        temp->next = temp->next->next;
        return head;

    }
};



//slow and fast pointer [optimal approach]
ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0; i<n; i++)
            fast=fast->next;


        if(fast==NULL)
        return head->next;

        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }