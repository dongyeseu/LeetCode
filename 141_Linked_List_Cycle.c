/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

//思路：创建快慢指针
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool hasCycle(struct ListNode *head) {
    struct ListNode * fast; //快结点
    struct ListNode * slow; //快结点
    fast = head;
    slow = head;
    if(head)
    {
        while(fast!= NULL && slow!=NULL)
        {
             slow = slow->next;
            if(fast->next!=NULL)
                fast = fast->next->next;
            else
                fast = head;
            if(fast == slow)
                return true;
        }
        return false;
    }
    else
        return false;
}
