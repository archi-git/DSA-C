int Max3( int A, int B, int C )
2.{ /* 返回3个整数中的最大值 */
3.    return A > B ? A > C ? A : C : B > C ? B : C;
4.}
5. 
6.int DivideAndConquer( int List[], int left, int right )
7.{ /* 分治法求List[left]到List[right]的最大子列和 */
8.    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
9.    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/
10. 
11.    int LeftBorderSum, RightBorderSum;
12.    int center, i;
13. 
14.    if( left == right )  /* 递归的终止条件，子列只有1个数字 */
15.        if( List[left] > 0 )  return List[left];
16.        else return 0;
17. 
18.    /* 下面是"分"的过程 */
19.    center = ( left + right ) / 2; /* 找到中分点 */
20.    /* 递归求得两边子列的最大和 */
21.    MaxLeftSum = DivideAndConquer( List, left, center );
22.    MaxRightSum = DivideAndConquer( List, center+1, right );
23. 
24.    /* 下面求跨分界线的最大子列和 */
25.    MaxLeftBorderSum = 0; LeftBorderSum = 0;
26.    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
27.        LeftBorderSum += List[i];
28.        if( LeftBorderSum > MaxLeftBorderSum )
29.            MaxLeftBorderSum = LeftBorderSum;
30.    } /* 左边扫描结束 */
31. 
32.    MaxRightBorderSum = 0; RightBorderSum = 0;
33.    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
34.        RightBorderSum += List[i];
35.        if( RightBorderSum > MaxRightBorderSum )
36.            MaxRightBorderSum = RightBorderSum;
37.    } /* 右边扫描结束 */
38. 
39.    /* 下面返回"治"的结果 */
40.    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
41.}
42. 
43.int MaxSubseqSum3( int List[], int N )
44.{ /* 保持与前2种算法相同的函数接口 */
45.    return DivideAndConquer( List, 0, N-1 );
46.}
