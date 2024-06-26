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
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        int mid = count/2;
        count=1;
        temp=head;
        for(int i=1; i<=mid; i++)
        {
            temp=temp->next;
        }
        return temp;
    }
};




class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return (fast->next) ? slow->next : slow;
    }
};