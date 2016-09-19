typedef struct LNode *PtrToLNode;
2.struct LNode {
3.    ElementType Data;
4.    PtrToLNode Next;
5.};
6.typedef PtrToLNode Position;
7.typedef PtrToLNode List;
8. 
9./* 查找 */
10.#define ERROR NULL
11. 
12.Position Find( List L, ElementType X )
13.{
14.    Position p = L; /* p指向L的第1个结点 */
15. 
16.    while ( p && p->Data!=X )
17.        p = p->Next;
18. 
19.    /* 下列语句可以用 return p; 替换 */
20.    if ( p )
21.        return p;
22.    else
23.        return ERROR;
24.}
25. 
26./* 带头结点的插入 */
27./*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
28.bool Insert( List L, ElementType X, Position P )
29.{ /* 这里默认L有头结点 */
30.    Position tmp, pre;
31. 
32.    /* 查找P的前一个结点 */        
33.    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
34.    if ( pre==NULL ) { /* P所指的结点不在L中 */
35.        printf("插入位置参数错误\n");
36.        return false;
37.    }
38.    else { /* 找到了P的前一个结点pre */
39.        /* 在P前插入新结点 */
40.        tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
41.        tmp->Data = X; 
42.        tmp->Next = P;
43.        pre->Next = tmp;
44.        return true;
45.    }
46.}
47. 
48./* 带头结点的删除 */
49./*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
50.bool Delete( List L, Position P )
51.{ /* 这里默认L有头结点 */
52.    Position tmp, pre;
53. 
54.    /* 查找P的前一个结点 */        
55.    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
56.    if ( pre==NULL || P==NULL) { /* P所指的结点不在L中 */
57.        printf("删除位置参数错误\n");
58.        return false;
59.    }
60.    else { /* 找到了P的前一个结点pre */
61.        /* 将P位置的结点删除 */
62.        pre->Next = P->Next;
63.        free(P);
64.        return true;
65.    }
66.}
