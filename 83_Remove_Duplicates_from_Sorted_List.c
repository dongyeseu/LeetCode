/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/


/*
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//注意空链表以及只有一个元素的链表
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode * temp,*del; //临时节点
    temp = malloc(sizeof(struct ListNode));  //分配内存
    temp = head;
    if(head==NULL || head->next == NULL)
        return head; 
    while(temp->next!=NULL)
    {
        if(temp->next->val == temp->val)
        {
            del = temp->next;
            temp->next = del->next;
            free(del);
        }
        else
            temp = temp->next;
    }
    return head;
}

//更简洁的写法
if (head) {
  struct ListNode *p = head;
  while (p->next) {
  if (p->val != p->next->val) {
    p = p->next;
  }
  else {
    struct ListNode *tmp = p->next;
    p->next = p->next->next;
      free(tmp);
   }
  }
  }
return head;
