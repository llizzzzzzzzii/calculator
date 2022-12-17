#include "queue.h"
#include <stdlib.h>


NODE *head=NULL;
STATE state=NORMAL;

void push_back(int value)
{
    NODE** temp=&head;
    while (*temp)
    {
        temp=&(*temp)->next;
    }
    NODE* p=(NODE*) malloc(sizeof(NODE));
    p->value=value;
    p->next=NULL;
    *temp=p;
    state=NORMAL;
}
void pop_front()
{
    if (head)
    {
        NODE* temp=head->next;
        free(head);
        head=temp;
        state=NORMAL;
    }
    else {
        state = UNDERFLOW;
    }
}
int is_empty()
{
    state=NORMAL;
    if (head)
        return 0;
    return 1;

}
int top()
{
    if (head)
    {
        state=NORMAL;
        return head->value;
    }
    state=EMPTY;
}

