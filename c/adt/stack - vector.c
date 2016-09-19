#include <stdio.h>
#include <stdlib.h>
typedef int Position;
typedef int ElementType;

struct SNode{
    ElementType *Data;
    Position Top;
    int MaxSize;
};
typedef struct SNode *Stack;
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}
bool IsEmpty( Stack S)
{
    return (S->Top == -1);
}
ElementType Pop( Stack S)
{
    if (IsEmpty(S)){
        printf("Stack is empty.\n");
        return 0;
    }
    else 
        return (S->Data[(S->Top)--]);
}
bool IsFull( Stack S)
{
    return (S->Top == S->MaxSize - 1);
}
bool Push( Stack S, ElementType X )
{
    if (IsFull(S)){
        printf("Stack is full\n");
        return false;
    }
    else
    {
        S->Data[++(S->Top)] = X;
        return true;
    }
}
int main()
{
    Stack S = CreateStack(5);
   
}
