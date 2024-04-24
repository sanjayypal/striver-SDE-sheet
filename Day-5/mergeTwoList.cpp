
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newnode = new ListNode(-1);
        ListNode* temp = newnode;
        ListNode* head1=list1;
        ListNode* head2=list2;
        if(head1==NULL)
        return head2;
        if(head2==NULL)
        return head1;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val < head2->val)
            {
                temp->next = head1;
                temp=head1;
                head1=head1->next;
            }
            else
            {
                temp->next = head2;
                temp=head2;
                head2=head2->next;
            }
        }
        if(head1!=NULL)
        temp->next = head1;
        if(head2!=NULL)
        temp->next = head2;
        return newnode->next;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val>list2->val) swap(list1,list2);

        ListNode* head=list1;
    
        while(list1 && list2){
            ListNode* temp=NULL;
            while(list1 && list1->val<=list2->val){
                temp= list1;
                list1=list1->next;
            }
            temp->next = list2;
            swap(list1,list2);
        }
        return head;
    }
};


class Solution {
public:
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		if(l1 == NULL)
        {
			return l2;
		}
		if(l2 == NULL)
        {
			return l1;
		} 
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};