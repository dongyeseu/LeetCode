/*

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/





/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode * NewH, *current , *prev;
    while(head == NULL)
        return NULL;
    while(head)
    {
        if(head->val == val)
        {
            head = head->next;   
        }
        else
        {
            current = malloc(sizeof(struct ListNode));
            current->val = head->val;
            current->next = NULL;
            if(NewH==NULL)
                NewH = current;
            else
                prev->next = current;
            prev = current;
            head = head->next;
        }
    }
    return NewH;
    
}






//指针和指针的指针（不多生成内存）
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode **pp, *p;

    pp = &head;
    while (*pp) {
        p = *pp;
        if ((*pp)->val == val) { /* found one */
            *pp = p->next;
            free(p);
        } else
            pp = &p->next;
    }

    return head;
}
