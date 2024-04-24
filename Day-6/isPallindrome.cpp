#include <bits/stdc++.h>
using namespace std;

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

//Using Array
class Solution {
public:
    bool isPalindrome(ListNode* head) {
         vector<int> listVals;
        while (head) {
            listVals.push_back(head->val);
            head = head->next;
        }
        
        int left = 0, right = listVals.size() - 1;
        while (left < right && listVals[left] == listVals[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
};



//Using Stack
  bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode* curr = head;
        while (curr) {
            stack.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr && curr->val == stack.top()) {
            stack.pop();
            curr = curr->next;
        }
        return curr == nullptr;
    }


    //Using Recursion
    class Solution {
    ListNode* curr;
public:
    bool isPalindrome(ListNode* head) {
        curr = head;
        return solve(head);
    }

    bool solve(ListNode* head) {
        if (head == nullptr) return true;
        bool ans = solve(head->next) && head->val == curr->val;
        curr = curr->next;
        return ans;
    }
};


//Optimal Solution
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow);
        while (rev != nullptr) {
            if (head->val != rev->val) {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }