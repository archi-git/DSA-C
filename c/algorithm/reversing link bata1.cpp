#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode
{
	int value;
	int addr;
	int nextAddr;
	struct PolyNode * link;
}*Polynomial;

Polynomial ReadPoly (void);
Polynomial SortPoly (Polynomial tP);
Polynomial ReversePoly (Polynomial rP);
void PrintPoly (Polynomial P);
void Attach(int tempValue,int tempHead,int tempNext,Polynomial * Rear);
Polynomial MoveIndex(int k,Polynomial P);
Polynomial Find (Polynomial P, int num); 


int headAddr,N,K;

int main()
{	

	Polynomial P,sortedP;
	P = ReadPoly();
	P = SortPoly(P);
    P = ReversePoly(P);
	PrintPoly(P);

	return 0;
}

Polynomial Find (Polynomial P, int num)
{
	Polynomial tP = P;
	120
	for(;tP->value != num && tP->link;tP = tP->link);
	tP->link = NULL;  

	if(tP->value == num ) printf("find %d was successed :%d\n",num,tP->value);
	else {
		printf("find %d was failed \n",num);
	;}
	return tP;

}



Polynomial ReadPoly ()
{	
	
	scanf("%d %d %d",&headAddr,&N,&K) ;
	
	
//	scanf("%d %d",&headAddr,&K);

	Polynomial P,Rear,t;
	P = (PolyNode*)malloc(sizeof(PolyNode));
	P->link = NULL;
	Rear = P;
	for(int i = N;i > 0;i--) 
	{
		int tempValue;
		int tempHead,tempNext;
		scanf("%d %d %d",&tempHead,&tempValue,&tempNext);
		Attach(tempValue,tempHead,tempNext,&Rear);
    }
    t = P;
    P = P->link;
    free(t);

    return P;
}

void Attach(int tempValue,int tempHead,int tempNext,Polynomial *Rear)
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->link = NULL;
	P->value = tempValue;
	P->addr = tempHead;
	P->nextAddr = tempNext;
	(*Rear)->link = P;
	*Rear = P;
}

void PrintPoly (Polynomial P)
{
	while (P)
	{
		printf("%d %d %d\n",P->addr,P->value,P->nextAddr);
		P = P->link;
	}
}

Polynomial ReversePoly(Polynomial rP)
{	
	printf("N = %d and K = %d\n",N,K );

	Polynomial P,t,rear;
	P = (Polynomial)malloc(sizeof(PolyNode));
	rear = P;
	P->link = NULL;

	int q = N / K; //要reverse几段

	for (int i = 1; i <= q; i ++) //逐段reverse
	{	
		for(int j = i * K;j <= i * K && j > K * (i - 1); j--) 	
		{
			Polynomial p;
			p = Find(rP,j);
			int he = p->value;
		//	printf("p's value is %s\n",he);
			Attach(p->value,p->addr,p->nextAddr,&rear);
			//printf("i =  %d and j = %d\n",i,j );
		}
		
	}
	
		
	for ( int l = q * K + 1; l <= N ; l ++)
	{
		Polynomial pp = Find(rP,l);
		Attach(pp->value,pp->addr,pp->nextAddr,&rear);
	}
	
	t = P;
	P = P->link;
	free(t);
	return P;
}

Polynomial SortPoly (Polynomial tP)
{	
	Polynomial P,t,rear,ttP = tP;
	P = (Polynomial)malloc(sizeof(PolyNode));
	rear = P;
	P->link = NULL;
	
	for (int i = N;i;i--)
	{
		tP = ttP;
		while(tP->addr != headAddr)
		{
			if(tP->link) tP = tP->link ;
			else return 0;
		};
		Attach(tP->value,tP->addr,tP->nextAddr,&rear);
		headAddr = tP->nextAddr;	
	
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}

Polynomial MoveIndex(int k,Polynomial P){
	for (int i = k; k > 0; k --)
	{
		if (P->link) P = P->link;
	} 
	return P;
}

