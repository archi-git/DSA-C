#include <stdlib.h>
#include <stdio.h>
// FILE *fp;
typedef struct Node *Poly;
struct Node {
	int coef;
	int expon;
	Poly Next;
};

void append(Poly P, int coef, int expon)
{
	while (P->Next && P->Next->expon > expon) P = P->Next; 	  //移动到合适的位置append

	if (P->Next && P->Next->expon == expon){	
		P->Next->coef += coef;		//指数相同时合并
	}else{
		Poly temp = (Poly)malloc(sizeof(struct Node));		//指数不同时新建节点
		Poly Next = NULL;
		if (P->Next) Next = P->Next;
		temp->Next = Next;
		temp->coef = coef;
		temp->expon = expon;
		P->Next = temp;
	}
}

Poly Multiply( Poly P1, Poly P2 )
{
    Poly L1 = P1, L2 = P2;			//备份头节点位置，循环时要用到

    Poly L = (Poly)malloc(sizeof(struct Node));
    Poly head = L;
    L->coef = NULL;
    L->expon = NULL;
    L->Next = NULL;

    while (L1->Next)	//先用L2的第一个节点分别乘L1的每个节点
    {
        int temCoef = L1->Next->coef * L2->Next->coef, temExpon = L1->Next->expon + L2->Next->expon;
        append(L, temCoef, temExpon);
        L1 = L1->Next;
    }
    L2 = L2->Next;		//L2后移一位。

    for (; L2->Next; L2 = L2->Next)		//L1和L2 双层循环，两两相乘；
    {   
        L1 = P1;
        for (; L1->Next; L1 = L1->Next)
        {
            int temCoef = L1->Next->coef * L2->Next->coef, temExpon = L1->Next->expon + L2->Next->expon;
            append(L, temCoef, temExpon);
        }
    }
    return L;

}

Poly Add ( Poly P1, Poly P2 )
{
    Poly L1 = P1, L2 = P2;

    Poly L = (Poly)malloc(sizeof(struct Node));
    Poly Temp = L;			//记住合并后的列表的头，最后要返回
    L->Next = NULL; 
    L->coef = NULL;
    L->expon = NULL;

    while (L1->Next && L2->Next)		//比较指数大小，大的先append
    {
        if (L1->Next->expon >= L2->Next->expon)
        {
            append(L, L1->Next->coef, L1->Next->expon);
            L1 = L1->Next;
        }
        else
        {
            append(L, L2->Next->coef, L2->Next->expon);
            L2 = L2->Next;
        }
    }

    while (L1->Next) 	//append剩下的一条尾巴
    {     
        append(L, L1->Next->coef, L1->Next->expon); 
        L1 = L1->Next;
    }
    while (L2->Next) 
    {     
    	append(L, L2->Next->coef, L2->Next->expon);
        L2 = L2->Next;
    }
    
    return Temp;
}


Poly build (void)
{
	Poly P = (Poly)malloc(sizeof(struct Node));
	P->coef = NULL;
	P->expon = NULL;
	P->Next = NULL;
	Poly rear = P;
	int n;
	scanf( "%d", &n);
	while (n--)
	{
		Poly temp = (Poly)malloc(sizeof(struct Node));
		temp->Next = NULL;
		scanf( "%d %d", &temp->coef, &temp->expon);
		P->Next = temp;
		P = P->Next;
	}
	return rear;	
}
void print ( Poly P)
{
	while (P->Next)
	{
		printf("%d %d ", P->Next->coef, P->Next->expon);
		P = P->Next;
	}
	printf("\n");
}

int main()
{
	// fp = fopen ("td.txt", "r" );
	Poly P1 = build();
	Poly P2 = build();
	Poly P3 = Add(P1, P2);
	Poly P4 = Multiply(P1, P2);
	
	print(P4);
	print(P3);
	
	// fclose (fp);
	return 0;
}