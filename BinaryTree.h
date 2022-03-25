typedef struct nodeBT {
    Elem R;
    struct nodeBT *l;
    struct nodeBT *r;
} *BinaryTree;

BinaryTree empty() {
    return NULL;
}

BinaryTree createBT(Elem r, BinaryTree i, BinaryTree d) {
    BinaryTree t = (BinaryTree) malloc(sizeof(struct nodeBT));
    t->R = r;
    t->l = i;
    t->r = d;
    return t;
}

int isEmpty(BinaryTree a) { return a == NULL; }

Elem root(BinaryTree a) { return a->R; }

BinaryTree leftBT(BinaryTree a) { return a->l; }

BinaryTree rightBT(BinaryTree a) { return a->r; }

// Leaf -> It's the node where both of its 'children' are empty or null
int isLeaf(BinaryTree a)
{
    return isEmpty(leftBT(a)) && isEmpty(rightBT(a));
}

// Internal node -> It's the node where both (or just one) of its 'children' are not empty or null
int isInternal(BinaryTree a)
{
    return !isLeaf(a);
}


// Level -> is the length of the unique path from the root to the node
// Height -> Maximum level of the
int greatEqual(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int height(BinaryTree a)
{
    if(isLeaf(a))
        return 0;
    else
        return 1 + greatEqual(height(leftBT(a)), height(rightBT(a)));
}

