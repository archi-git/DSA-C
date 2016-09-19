typedef int Position;
2.struct QNode {
3.    ElementType *Data;     /* 存储元素的数组 */
4.    Position Front, Rear;  /* 队列的头、尾指针 */
5.    int MaxSize;           /* 队列最大容量 */
6.};
7.typedef struct QNode *Queue;
8. 
9.Queue CreateQueue( int MaxSize )
10.{
11.    Queue Q = (Queue)malloc(sizeof(struct QNode));
12.    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
13.    Q->Front = Q->Rear = 0;
14.    Q->MaxSize = MaxSize;
15.    return Q;
16.}
17. 
18.bool IsFull( Queue Q )
19.{
20.    return ((Q->Rear+1)%Q->MaxSize == Q->Front);
21.}
22. 
23.bool AddQ( Queue Q, ElementType X )
24.{
25.    if ( IsFull(Q) ) {
26.        printf("队列满");
27.        return false;
28.    }
29.    else {
30.        Q->Rear = (Q->Rear+1)%Q->MaxSize;
31.        Q->Data[Q->Rear] = X;
32.        return true;
33.    }
34.}
35. 
36.bool IsEmpty( Queue Q )
37.{
38.    return (Q->Front == Q->Rear);
39.}
40. 
41.ElementType DeleteQ( Queue Q )
42.{
43.    if ( IsEmpty(Q) ) { 
44.        printf("队列空");
45.        return ERROR;
46.    }
47.    else  {
48.        Q->Front =(Q->Front+1)%Q->MaxSize;
49.        return  Q->Data[Q->Front];
50.    }
51.}
