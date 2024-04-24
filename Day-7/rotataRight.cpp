//Brute Force Solution
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0)
        return head;
        ListNode* temp = head;
        vector<int> arr;
        while(temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        if(k>arr.size())
        k=k%arr.size();
        k = arr.size() - k;
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        reverse(arr.begin(),arr.end());
        temp = head;
        int i = 0;
        while(temp)
        {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};



//Optimal Solution
ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(head==NULL)
        return NULL;
        int count = 1;
        while(temp->next)
        {
            count++;
            temp = temp->next;
        }
        ListNode* temp1 = temp;
        temp = head;
        if(count<k)
        k = k % count;
        if(count==k)
        return head;
    
        count = count - k;
        int i = 1;
        while(i<count)
        {
            temp = temp->next;
            i++;
        }
        temp1->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;

    }