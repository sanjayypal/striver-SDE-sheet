 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp;
        while(headA)
        {
            temp=headB;
            while(temp)
            {
                if(temp==headA)
                return headA;
                temp = temp->next;
            }
        }
        return NULL;
    }
};
 
 //Using Hashing
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       unordered_set<ListNode*> st;
       while(headA)
       {
        st.insert(headA);
        headA = headA->next;
       }
       while(headB)
       {
        if(st.find(headB)!=st.end())
        return headB;
        headB=headB->next;
       }
       return NULL;
    }


    //Using Difference in Length

    int getDifference(ListNode* head1,ListNode* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}


ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    int diff = getDifference(head1,head2);
        if(diff < 0) 
            while(diff++ != 0) head2 = head2->next; 
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;
    }