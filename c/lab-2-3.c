#include <stdio.h>
#include <stdlib.h>
FILE *fp;
typedef struct Node *List;
struct Node
{
	char* add;
	int val;
	char* next;
	List Next;
};

List build (){
	int n, N, headAdd;
	fscanf(fp, "%d %d %d", &headAdd, &N, &n);

	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	L->add = NULL;
	L->val = NULL;
	L->next = NULL;
	List head = L;

	while(N--)
	{
		List L1 = (List)malloc(sizeof(struct Node));
		L1->Next = NULL;
		fscanf(fp, "%s %d %s ", &L1->add, &L1->val, &L1->next);
		L->Next = L1;
		L = L->Next;
	}
	return head;
}

void print(List L)
{
	while (L->Next)
	{
		printf("%s %d %s\n", &L->Next->add, &L->Next->val, &L->Next->next );
	}
}

int main(){
	fp = fopen("td.txt", "r");
	List L = build();
	print(L);
	fclose(fp);
	return 0;
}


