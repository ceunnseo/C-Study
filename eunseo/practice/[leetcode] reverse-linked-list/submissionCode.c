// runtine 0ms, memory 6.2MB
struct ListNode* reverseList(struct ListNode* head){
  struct ListNode * cur = head;
  struct ListNode * prev = NULL;
  while (cur != NULL)
  {
      cur = head -> next;
      head->next = prev;
      prev = head;
      head = cur;
  }
  head = prev;
  return head;
}
