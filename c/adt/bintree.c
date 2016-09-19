typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */

struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};

void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InorderTraversal( BT->Right );
    }
}

void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}

void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}

void LevelorderTraversal ( BinTree BT )
{ 
    Queue Q; 
    BinTree T;

    if ( !BT ) return; /* 若是空树则直接返回 */
    Q = CreatQueue(); /* 创建空队列Q */
    AddQ( Q, BT );

    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->Data); /* 访问取出队列的结点 */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}

// search tree
Position Find ( ElementType X, BinTree BST)
{
    while (BST)
    {
        if (X < BST->Data)  BST = BST->Left;
        else if (X >　BST->Data)  BST = BST->Righ;
        else return BST;
    }
    return NULL;
}

BinTree Insert ( ElementType X, BinTree BST)
{
    if (!BST)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else 
    {
        if (X < BST->Data) BST->Left = Insert(BST->Left, X);
        else if (X > BST->Data) BST->Right = Insert(BST->Right, X);
    }
    return BST;
}
BinTree Delete (ElementType X, BinTree BST)
{
    if (!BST) printf("Element was not founded\n");
    else if (X < BST->Data) Delete (X, BST->Left);
    else if (X > BST->Data) Delete (X, BST->Right);
    else 
        if (BST->Left && BST->Right) 
        {
            Tmp = FindMin(BST->Right);
            BST->Data = Tmp->Data;
            BST->Right = Delete (BST->Data, BST->Right);
        }
        else 
        {
            Tmp = BST;
            if (!BST->Left) BST = BST->Right;
            else if (!BST->Right) BST = BST->Left;
            free (Tmp);
        }
        return BST;
} 