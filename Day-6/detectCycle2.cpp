/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Brute Force 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
       unordered_set<ListNode*> hashMap;
        while(temp)
        {
            if(hashMap.find(temp)!=hashMap.end())
            return temp;
            else
            {
                hashMap.insert(temp);
                temp=temp->next;
            }
        }
        return NULL;
    }
};


//Using Fast and Slow 
ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
            {
                ListNode* temp = head;
                while(slow)
                {
                    if(slow==temp)
                    return slow;
                    slow=slow->next;
                    temp=temp->next;
                }
            }

        }
        return NULL;
    }