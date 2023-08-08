#define _CRT_SECURE_NO_WARNINGS //visual studio 사용자 한정
#include <stdio.h>

int main()
{
    struct Listnode
    {
        int val;
        struct ListNode* next;
    };

    struct ListNode* reverseList(struct ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        struct ListNode* p1;
        struct ListNode* q;
        q = head->next;
        head->next = NULL; //끝까지 도달했음
        while (q->next != NULL)
        {
            p1 = q->next;
            q->next = head;
            head = q;
            q = p1;
        }
        q->next = head;
        head = q;
        return head;
    };
}
