#include <stdio.h>
#define position int
#define ElementType int
struct stackNode{
	ElementType *Data;
	int capacity;
	position top;
};
typedef struct stackNode *Stack;

Stack Create ( int capacity ){
	Stack S = (Stack)malloc(sizeof(struct stackNode));
	S->Data = (ElementType*)malloc(sizeof(ElementType) * capacity);
	S->capacity = capacity;
	S->top = -1;
	return S;
}

bool IsEmpty( Stack S ) {
	return S->top == -1;
}

bool IsFull ( Stack S ) {
	return S->top == S->capacity;
}

ElementType pull ( Stack S ) {
	if ( IsEmpty(S) ){
		printf("Stack empty");
		return;
	}
	return S->Data[top--];
}

bold push ( Stack S, ElementType X ){
	if ( IsFull(S) ){
		printf("Stack full");
		return false;
	}
	S->Data[++top] = X;
	return true;
}
int main()
{
	Stack S = Create(5);
	push( S, 1 );
	int i = pull( S );
	printf("%d", i);
	return 0;
}
