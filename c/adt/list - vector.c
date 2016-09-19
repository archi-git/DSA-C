typedef int Position;
2.typedef struct LNode *List;
3.struct LNode {
4.    ElementType Data[MAXSIZE];
5.    Position Last;
6.};
7. 
8./* 初始化 */
9.List MakeEmpty()
10.{
11.    List L;
12. 
13.    L = (List)malloc(sizeof(struct LNode));
14.    L->Last = -1;
15. 
16.    return L;
17.}
18. 
19./* 查找 */
20.#define ERROR -1
21. 
22.Position Find( List L, ElementType X )
23.{
24.    Position i = 0;
25. 
26.    while( i <= L->Last && L->Data[i]!= X )
27.        i++;
28.    if ( i > L->Last )  return ERROR; /* 如果没找到，返回错误信息 */
29.    else  return i;  /* 找到后返回的是存储位置 */
30.}
31. 
32./* 插入 */
33./*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
34.bool Insert( List L, ElementType X, Position P ) 
35.{ /* 在L的指定位置P前插入一个新元素X */
36.    Position i;
37. 
38.    if ( L->Last == MAXSIZE-1) {
39.        /* 表空间已满，不能插入 */
40.        printf("表满"); 
41.        return false; 
42.    }  
43.    if ( P<0 || P>L->Last+1 ) { /* 检查插入位置的合法性 */
44.        printf("位置不合法");
45.        return false; 
46.    } 
47.    for( i=L->Last; i>=P; i-- )
48.        L->Data[i+1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
49.    L->Data[P] = X;  /* 新元素插入 */
50.    L->Last++;       /* Last仍指向最后元素 */
51.    return true; 
52.} 
53. 
54./* 删除 */
55./*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
56.bool Delete( List L, Position P )
57.{ /* 从L中删除指定位置P的元素 */
58.    Position i;
59. 
60.    if( P<0 || P>L->Last ) { /* 检查空表及删除位置的合法性 */
61.        printf("位置%d不存在元素", P ); 
62.        return false; 
63.    }
64.    for( i=P+1; i<=L->Last; i++ )
65.        L->Data[i-1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
66.    L->Last--; /* Last仍指向最后元素 */
67.    return true;   
68.}
