#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
struct Node
{   
    int coef;
    int expon;
    List Next;
};
FILE *fp;
List Read();
void Print(List L);
List Multiply( List P1, List P2 );
List Add ( List P1, List P2 );
void append (List L, int coef, int expon);
int main(){
    
    fp = fopen("td.txt", "r");
    List P1 = Read();
    List P2 = Read();
    List P3 = Multiply(P1, P2);
    // List P4 = Add(P1, P2);
    Print(P3);
    // Print(P4);
    // append(P1, P2->Next->coef, P2->Next->expon); 
    // Print(P1);
    fclose(fp);
    return 0;
}

void append (List L, int coef, int expon)
{
    // List rear = L;
    for (; L->Next; L = L->Next)
        {
        }
    List Temp = (List)malloc(sizeof(struct Node));
    Temp->Next = L->Next;
    Temp->coef = coef;
    Temp->expon = expon;
    L->Next = Temp;
    // L = rear;
}

List Read()
{   
    int n;
    fscanf(fp, "%d", &n);
    List L = (List)malloc(sizeof(struct Node));
    List Rear = L;
    L->coef = NULL;
    L->expon = NULL;
    L->Next = NULL;
    while (n--)
    {
        List Temp = (List)malloc(sizeof(struct Node));
        fscanf(fp, "%d %d", &Temp->coef , &Temp->expon );
        Temp->Next = NULL;
        L->Next = Temp;
        L = L->Next;
    }  
    return Rear; 
}
void Print(List L)
{
    while (L->Next)
    {
        printf("%d %d ",L->Next->coef, L->Next->expon );
        L = L->Next;
    }
    printf("\n");
}

List Multiply( List P1, List P2 )
{
    List L1 = P1, L2 = P2;
    List L = (List)malloc(sizeof(struct Node));
    L->coef = NULL;
    L->expon = NULL;
    L->Next = NULL;
    while (L1->Next)
    {
        int temCoef = L1->Next->coef * L2->Next->coef, temExpon = L1->Next->expon * L2->Next->expon;
        append(L, temCoef, temExpon);
        L1 = L1->Next;
    }
    // L1 = P1->Next;
    L2 = L2->Next;
    for (; L2->Next; L2->Next = L2->Next->Next)
    {   
        L1 = P1;
        for (; L1->Next; L1->Next = L1->Next->Next)
        {
            int temCoef = L1->Next->coef * L2->Next->coef, temExpon = L1->Next->expon * L2->Next->expon;
            append(L, temCoef, temExpon);
        }
    }
    return L;

}
List Add ( List P1, List P2 )
{
    List L1 = P1, L2 = P2;
    List L = (List)malloc(sizeof(struct Node));
    List Temp = L;
    L->Next = NULL; 
    L->coef = NULL;
    L->expon = NULL;
    while (L1->Next && L2->Next)
    {
        if (L1->Next->expon > L2->Next->expon)
        {
            L->Next = L1->Next; 
            // append(L, L1->Next->coef, L1->Next->expon);
            L1->Next = L1->Next->Next;
        }
        else if (L1->Next->expon == L2->Next->expon)
        {
            L->Next = L1->Next;
            L->Next->coef = L1->Next->coef + L2->Next->coef;
            L1->Next = L1->Next->Next;
            L2->Next = L2->Next->Next;
        }
        else
        {
            L->Next = L2->Next; 
            L2->Next = L2->Next->Next;
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
