/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

bool isPalindrome(struct ListNode* head) {
    struct ListNode * slow = head;
    struct ListNode * fast = head;
    struct ListNode * aux = NULL; //用于反转前半部分链表
    while(fast!=NULL && fast->next!=NULL)
    {
        struct ListNode * temp = slow;
        fast = fast->next->next;
        slow = slow->next;
        temp->next = aux;
        aux = temp;
    }
    if(fast)
        slow = slow->next;
    while(slow&&aux->val == slow->val)
    {
        aux = aux->next;
        slow = slow->next;
    }
    return slow==NULL;
    
}
