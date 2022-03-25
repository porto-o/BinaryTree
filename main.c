#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "BinaryTree.h"

int numElems(BinaryTree);
void preFix(BinaryTree a);
void inFix(BinaryTree a);
void postFix(BinaryTree a);

/**
 *          100
 *         /   \
 *       /      \
 *     50        200
 * */

int main() {
    BinaryTree x = createBT(100, createBT(50,empty(), empty()),
                            createBT(200, empty(), empty()));
    printf("%d\n", numElems(x));
    printf("\nRecorrido prefijo\n");
    preFix(x);
    printf("\nRecorrido infijo\n");
    inFix(x);
    printf("\nRecorrido postfijo\n");
    postFix(x);
    printf("\nHeight: %d\n", height(x));


    return 0;
}

int numElems(BinaryTree a)
{
    if(isEmpty(a))
        return 0;
    else
        return 1 + numElems(leftBT(a)) + numElems(rightBT(a));
}

void inFix(BinaryTree a)
{
    if(!isEmpty(a)){
        inFix(leftBT(a));
        PrintElem(root(a));
        inFix(rightBT(a));
    }
}

void preFix(BinaryTree a)
{
    if(!isEmpty(a))
    {
        PrintElem(root(a));
        preFix(leftBT(a));
        preFix(rightBT(a));
    }
}

void postFix(BinaryTree a)
{
    if(!isEmpty(a))
    {
        postFix(leftBT(a));
        postFix(rightBT(a));
        PrintElem(root(a));
    }
}