typedef struct nodeAB {
    Elem R;
    struct nodeAB *l;
    struct nodeAB *r;
} *BinaryTree;

BinaryTree empty() {
    return NULL;
}

BinaryTree createBT(Elem r, BinaryTree i, BinaryTree d) {
    BinaryTree t = (BinaryTree) malloc(sizeof(struct nodeAB));
    t->R = r;
    t->l = i;
    t->r = d;
    return t;
}

int isEmpty(BinaryTree a) { return a == NULL; }

Elem root(BinaryTree a) { return a->R; }

BinaryTree leftBT(BinaryTree a) { return a->l; }

BinaryTree rightBT(BinaryTree a) { return a->r; }