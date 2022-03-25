#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "BinaryTree.h"

int numElems(BinaryTree);

int main() {
    BinaryTree x = createBT(100, createBT(50,empty(), empty()),
                            createBT(200, empty(), empty()));
    printf("%d\n", numElems(x));
    return 0;
}

int numElems(BinaryTree a)
{
    if(isEmpty(a))
        return 0;
    else
        return 1 + numElems(leftBT(a)) + numElems(rightBT(a));
}
