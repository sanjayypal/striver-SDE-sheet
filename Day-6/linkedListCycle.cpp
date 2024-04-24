/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Using HashTable
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        while(head)
        {
            if(st.find(head)!=st.end())
            return true;
            st.insert(head);
            head=head->next;
        }
        return false;
    }
};

//Using fast and slow pointer
  bool hasCycle(ListNode* head) {
        if(head==NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }