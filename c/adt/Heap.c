typedef struct HeapStruct *MaxHeap;	
struct HeapStruct {
	ElementType *Elements;
	int Capacity;
	int Size;
}
MaxHeap Create (int MaxSize)
{
	MaxHeap H = malloc( sizeof( struct HeapStruct));
	H->Elements = malloc ( (MaxSize+1) * sizeof (ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;
	return H;
}

void Insert (ElementType item, MaxHeap H)  
{
    int i ;
    if (IsFull(H)) {
        printf("Heap is empty\n");
        return;
    }
    i = ++ H->Size;
    for ( ; H->Elements[i/2] < item; i /= 2)  //循环做到哨兵会停止.哨兵要足够大
    {
        H->Elements[i] = H->Elements[i/2];
    } 
    H->Elements[i] = item;
}

ElementType DeleteMax (MaxHeap H)
{
    int Parent, Child;
    ElementType MaxItem, temp ;
    if (IsEmpty(H)) {
        printf("Heap is empty\n");
        return;
    }
    MaxItem = H->Elements[1];
    temp = H->Elements[size--];
    for (Parent = 1; Parent * 2 <= H->size; Parent = Child)
    {
        Child = Parent * 2;
        if ( (Child != H->size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child ++;
        if (temp >= H->Elements[Child]) break;
        else 
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}

//huffman
typedef struct TreeNode *HuffmanTree;
struct TreeNode {
    int weight;
    HuffmanTree Left, Right;
}
HuffmanTree Huffman (MinHeap H)
{
    HuffmanTree T;
    BuildMinHeap (H);
    for (int i = 1; i < H->size; i ++)
    {
        T = malloc(sizeof(struct TreeNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->weight = T->Left + T->Right;
        Insert (H, T);
    }
    T = DeleteMin(H);
    return T;
}

// 集合
typedef struct {
    ElementType Data;
    int Parent;
}SetType;
int Find (SetType S[], ElementType X)
{
    int i ;
    for (i = 0; i != S[i].Data && i < MaxSize; i++);
    if (i >= MaxSize) return -1;
    for (; S[i].Parent > 0; i = S[i].Parent);
    return i;
}

void Union (SetType S[], ElementType X1, ElementType X2){
    int root1, root2;
    root1 = Find (S, X1);
    root2 = Find (S, X2);
    if (root1 != root2) S[root1].Parent = Root2;
} 