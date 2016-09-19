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

bool IsPossible( Stack S, int src[], int N )
{       int j = 0;
    for (int i = 1; i <= N; i++ )
    {    
        while(S->Data[S->Top] != i)
        {
            if (j == N - 1 && src[j] != i) return false;    
            if (!Push(S, src[j++])) return false;
            // printf("%d\n", S->Data[S->Top]);
        } 
        Pop(S);  
    }
    return true;
}
int main()
{
    int N,M,K;//M: the capatity of the stack  N: the length of push sequence K: the line of number
    scanf("%d %d %d", &M, &N, &K);
    Stack S = CreateStack(M);
    int src[N];
    for (int i = 0; i < K; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &src[j]);
          
        }
        if (IsPossible(S, src, N))
            printf("YES\n");
        else
            printf("NO\n");
     
     
    }
    return 0;
}