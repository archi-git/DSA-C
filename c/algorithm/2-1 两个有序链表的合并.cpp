
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read()
{   
    List L, Rear;
    L = (List)malloc(sizeof(struct Node));
    Rear = L;
    L->Data = NULL;
    L->Next = NULL;
    int n = 0;
    scanf("%d", &n);
    while (n--)
    {   
        List Temp = (List)malloc(sizeof(struct Node));
        int value;
        scanf("%d", &value);
        Temp->Data = value;
        Temp->Next = NULL;
        L->Next = Temp;
        L = L->Next;
    }
    return Rear;
}; /* 细节在此不表 */
void Print( List L )
{
    if (!L->Next) printf("NULL\n");
    while(L->Next )
    {
        printf("%d\n",L->Next->Data );
        L = L->Next;
    }
}; /* 细节在此不表；空链表将输出NULL */

List Merge (List L1, List L2)
{
   
    List L = (List)malloc(sizeof(struct Node));
    List Temp = L;
    L->Next = NULL; 
    L->Data = NULL;
    while (L1->Next && L2->Next)
    {
        if (L1->Next->Data > L2->Next->Data)
        {
            L->Next = L2->Next; 
            L2->Next = L2->Next->Next;
        }
        else
        {
            L->Next = L1->Next; 
            L1->Next = L1->Next->Next;
        }
        L = L->Next;
    }
    while (L1->Next) 
    {     
        L->Next = L1->Next; 
        L1->Next = L1->Next->Next;
        L = L->Next;
    }
    while (L2->Next) 
    {     
        L->Next = L2->Next; 
        L2->Next = L2->Next->Next;
        L = L->Next;
    }
    return Temp;
}


int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}


