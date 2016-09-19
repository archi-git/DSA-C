typedef struct Node *PtrToNode;
2.struct Node { /* 队列中的结点 */
3.    ElementType Data;
4.    PtrToNode Next;
5.};
6.typedef PtrToNode Position;
7. 
8.struct QNode {
9.    Position Front, Rear;  /* 队列的头、尾指针 */
10.    int MaxSize;           /* 队列最大容量 */
11.};
12.typedef struct QNode *Queue;
13. 
14.bool IsEmpty( Queue Q )
15.{
16.    return ( Q->Front == NULL);
17.}
18. 
19.ElementType DeleteQ( Queue Q )
20.{
21.    Position FrontCell; 
22.    ElementType FrontElem;
23.     
24.    if  ( IsEmpty(Q) ) {
25.        printf("队列空");
26.        return ERROR;
27.    }
28.    else {
29.        FrontCell = Q->Front;
30.        if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
31.            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
32.        else                     
33.            Q->Front = Q->Front->Next;
34.        FrontElem = FrontCell->Data;
35. 
36.        free( FrontCell );  /* 释放被删除结点空间  */
37.        return  FrontElem;
38.    }
39.}
