#include <stdio.h>
#include "binaryTree.h"

int main() {
    BinaryTree_t *binaryTree = createBinaryTree();
    add(binaryTree, 8);
    add(binaryTree, 7);
    add(binaryTree, 6);
    printf("%d\n", binaryTree->root);
    for (int i = 0; i < 2; i++) {
        printf("%d\n", binaryTree->tree->trunk);
    }
    return 0;
}