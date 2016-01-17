#include "List.c"

int main (void)
{
    List L = malloc (sizeof (struct Node));
    L->Next = NULL;

    PrintList (L);
    Insert (1, L, L);   // 在链表头部插入元素
    Insert (2, L, L);
    PrintList (L);


    return 0;
}
