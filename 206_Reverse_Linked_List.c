


//思路一：迭代法
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode * NewH, *H;
    H = head;
    if(head == NULL || head->next == NULL)
        return head;
    NewH = NULL;
    while(H!=NULL)
    {
        struct NodeList * temp;
        temp = H->next;
        H->next = NewH;
        NewH = H;
        H = temp;
    }
    return NewH;
}


//思路二：递归法
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* reverseList(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL)       //链表为空直接返回，而H->next为空是递归基
        return head;
    struct ListNode * newHead = reverseList(head->next); //一直循环到链尾
    head->next->next = head;                       //翻转链表的指向
    head->next = NULL;                          //记得赋值NULL，防止链表错乱
    return newHead;                          //新链表头永远指向的是原链表的链尾
}
