#include <stdlib.h>
#include <stdio.h>
FILE *fp;
typedef struct Node *Poly;
struct Node {
	int coef;
	int expon;
	Poly Next;
};
Poly build (void)
{
	Poly P = (Poly)malloc(sizeof(struct Node));
	P->coef = NULL;
	P->expon = NULL;
	P->Next = NULL;
	Poly rear = P;
	int n;
	fscanf(fp, "%d", &n);
	while (n--)
	{
		Poly temp = (Poly)malloc(sizeof(struct Node));
		temp->Next = NULL;
		fscanf(fp, "%d %d", &temp->coef, &temp->expon);
		P->Next = temp;
		P = P->Next;
//		P->Next = NULL;		
	}
	return rear;	
}
void print ( Poly P)
{
	while (P->Next)
	{
		printf("%d %d\n", P->Next->coef, P->Next->expon);
		P = P->Next;
	}
}

int main()
{
	fp = fopen ("td.txt", "r" );
	Poly P1 = build();
	Poly P2 = build();
	
	print(P1); 
	print(P2); 
	fclose (fp);
	return 0;
}
